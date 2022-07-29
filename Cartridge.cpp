#include "Cartridge.hpp"

#include <iostream>


Cartridge::Cartridge() : debug(DebugLevel::None) {}

void Cartridge::defineSymbol(Symbol symbol) {
    symbols.push_back(symbol);
}

void Cartridge::defineRule(Rule rule) {
    ruleSet.push_back(rule);
}

void Cartridge::setStartingField(Pattern f) {
    field = f;
}

Pattern Cartridge::getField() {
    return field;
}

bool Cartridge::check() {
    //Check that the starting field is rectangular
    if (!field.isRectangular()) {
        if (debug >= DebugLevel::Print) {
        std::cerr << "Error: field is misshapen" << std::endl;
        }
        return false;
    }
    //Check that the starting field is not empty (uninitialized)
    if (field.isEmpty()) {
        if (debug >= DebugLevel::Print) {
        std::cerr << "Error: field is empty" << std::endl;
        }
        return false;
    }
    //Check that the starting field does not contain wildcards
    if (field.containsWildcard()) {
        if (debug >= DebugLevel::Print) {
        std::cerr << "Error: field contains wildcard" << std::endl;
        }
        return false;
    }
    //Check that all symbols occurring in the starting field have been declared
    if (!field.madeUpOf(symbols)) {
        if (debug >= DebugLevel::Print) {
        std::cerr << "Error: undeclared symbols in field" << std::endl;
        }
        return false;
    }
    //For every rule...
    for (int i = 0; i < ruleSet.size(); i++) {
        Pattern lhs = ruleSet[i].getLhs();
        Pattern rhs = ruleSet[i].getRhs();
        //Check that both patterns are actually rectangular
        if (!lhs.isRectangular()) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: LHS of rule " << std::to_string(i) << " is misshapen" << std::endl;
            }
            return false;
        }
        if (!rhs.isRectangular()) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: RHS of rule " << std::to_string(i) << " is misshapen" << std::endl;
            }
            return false;
        }
        //Check that all symbols occurring on both sides of the rule are declared or wildcards
        if (!lhs.madeUpOf(symbols)) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: undeclared symbols in LHS of rule " << std::to_string(i) << std::endl;
            }
            return false;
        }
        if (!rhs.madeUpOf(symbols)) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: undeclared symbols in RHS of rule " << std::to_string(i) << std::endl;
            }
            return false;
        }
        //Check that both sides have the same shape
        if (lhs.getHeight() != rhs.getHeight()) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: height mismatch in rule " << std::to_string(i) << std::endl;
            }
            return false;
        }
        if (lhs.getWidth() != rhs.getWidth()) {
            if (debug >= DebugLevel::Print) {
            std::cerr << "Error: width mismatch in rule " << std::to_string(i) << std::endl;
            }
            return false;
        }
    }
    //If all tests have been passed, cartridge is valid
    return true;
}

void Cartridge::execute() {
    srand(time(NULL)); //Initialize RNG
    int ruleIndex = 0; //Start with the first rule
    int numberOfRules = ruleSet.size();

    if(debug == DebugLevel::Verbose) {
        field.prettyPrint(); //show initial state
    }

    uint64_t before = timeSinceEpochMillisec();

    while(ruleIndex < numberOfRules) {
        if (ruleSet[ruleIndex].canBeUsed() && field.apply(ruleSet[ruleIndex])) {
            /*If a rule is not exhausted and it catually applies successfully,
            consume one of its uses, return to the top of the ruleset and continue*/
            if(debug == DebugLevel::Verbose) {
                std::cout << "Applied rule " << std::to_string(ruleIndex) << std::endl;
                field.prettyPrint();
            } 
            ruleSet[ruleIndex].consume();
            ruleIndex = 0;
        } else {
            //Otherwise we check the next rule
            ruleIndex++;
        }
    }

    uint64_t delay = timeSinceEpochMillisec() - before;

    if (debug >= DebugLevel::Print) {
        std::cout << "Done in " << std::to_string(delay) << "ms" << std::endl;
        field.prettyPrint();
    }
}

void Cartridge::setDebugLevel(DebugLevel dl) {
    debug = dl;
}

std::string Cartridge::toString() {
    std::string symbolString = "Symbols: [";
    for (int i = 0; i < symbols.size(); i++) {
        symbolString += symbols[i].toString();
        if (i != symbols.size()-1) {
            symbolString += ", ";
        }
    }
    symbolString += "]\n";
    std::string ruleString = "Rules: [\n";
    for (int i = 0; i < ruleSet.size(); i++) {
        ruleString += "#" + std::to_string(i) + ": ";
        std::string arrowString = " -";
        if(ruleSet[i].getUses()>=0) {
            arrowString += std::to_string(ruleSet[i].getUses());
        }
        arrowString += "> ";
        ruleString += ruleSet[i].getLhs().toString() + arrowString + ruleSet[i].getRhs().toString() + "\n";
    }
    ruleString += "]\n";
    std::string startingFieldString = "Field: \n" + field.toString();
    
    return symbolString + ruleString + startingFieldString;
}

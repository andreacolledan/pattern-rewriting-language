#pragma once 

#include "Rule.hpp"

#include <vector>

enum class DebugLevel {
    None, Print, Verbose
};

/**
 * @brief This class wraps all the data needed to represent a single PRL program.
 * It defines an API to the PRL engine.
 * 
 * When invoking PRL's interpreter, a cartrididge is generated from the source code and run,
 * but the cartridge API is designed to also make PRL usable as a library.
 * 
 */
class Cartridge {
    public:
        Cartridge();

        void defineSymbol(Symbol symbol);

        void defineRule(Rule rule);

        void setStartingField(Pattern field);
        Pattern getField();

        bool check();

        void execute();

        void setDebugLevel(DebugLevel dl);
        
    private:
        std::vector<Symbol> symbols;
        std::vector<Rule> ruleSet;
        Pattern field;
        DebugLevel debug;

        static uint64_t timeSinceEpochMillisec() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }
};

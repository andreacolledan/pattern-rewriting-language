#include <iostream>
#include <fstream>

#include "grammar/antlr4-runtime/PRLLexer.h"
#include "grammar/antlr4-runtime/PRLParser.h"
#include "ParserVisitor.hpp"

#include "Cartridge.hpp"

int main(int, char**) {
    std::ifstream stream;
    stream.open("examples/islands.prl");
    
    antlr4::ANTLRInputStream input(stream);
    PRLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    PRLParser parser(&tokens);
    PRLParser::ProgContext* tree = parser.prog();
    ParserVisitor visitor;
    Cartridge cartridge = visitor.visitProg(tree).as<Cartridge>();

    cartridge.setDebugLevel(DebugLevel::Print);
    //std::cout << cartridge.toString() << std::endl;
    if(cartridge.check()) {
        cartridge.execute();
    }

    return 0;
}

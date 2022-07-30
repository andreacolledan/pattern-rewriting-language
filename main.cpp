#include <iostream>
#include <fstream>

#include "subprojects/argparse/include/argparse/argparse.hpp"

#include "grammar/antlr4-runtime/PRLLexer.h"
#include "grammar/antlr4-runtime/PRLParser.h"
#include "ParserVisitor.hpp"

#include "Cartridge.hpp"

int main(int argc, char** argv) {

    //Parse arguments

    argparse::ArgumentParser arguments("prl");

    arguments.add_argument("filename")
    .help("path to the PRL file to run");

    arguments.add_argument("--verbose")
    .help("print intermediate steps of the computation")
    .default_value(false)
    .implicit_value(true);

    arguments.add_argument("--silent")
    .help("do not print program output to stdout")
    .default_value(false)
    .implicit_value(true);

    try {
        arguments.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << arguments;
        std::exit(1);
    }

    if (arguments.get<bool>("--silent") && arguments.get<bool>("--verbose")) {
        std::cerr << "Error: incompatible flags --silent and --verbose have been provided." << std::endl;
        std::exit(1);
    }

    //Get input file contents

    std::string inputFileName = arguments.get<std::string>("filename");
    std::ifstream stream;
    stream.open(inputFileName);
    if (stream.fail()) {
        std::cerr << "Error: could not open " << inputFileName << ". It might not exist." << std::endl;
        std::exit(1);
    }

    //Set debug level

    DebugLevel debug = DebugLevel::Print;
    if(arguments.get<bool>("--silent")) {
        debug = DebugLevel::None;
    }
    if(arguments.get<bool>("--verbose")) {
        debug = DebugLevel::Verbose;
    }

    //Parse
    
    antlr4::ANTLRInputStream input(stream);
    PRLLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    PRLParser parser(&tokens);
    PRLParser::ProgContext* tree = parser.prog();
    ParserVisitor visitor;
    Cartridge cartridge = visitor.visitProg(tree).as<Cartridge>();

    //Check cartridge and run it

    cartridge.setDebugLevel(debug);
    if(cartridge.check()) {
        cartridge.execute();
    }

    return 0;
}

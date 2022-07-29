#pragma once 

#include "Rule.hpp"

#include <vector>
#include <chrono>

/**
 * @brief The amount of information to send to stdout during execution of the cartridge
 * 
 */
enum class DebugLevel {
    /**
     * @brief No information is printed
     */
    None,
    /**
     * @brief Only the final state and the elapsed time are printed
     */
    Print, 
    /**
     * @brief Initial, intermediate and final states are printed
     */
    Verbose
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

        std::string toString();
        
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

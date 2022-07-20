#pragma once

#include <string>

/**
 * @brief Implements an atomic symbol, which might be a character or a wildcard symbol.
 * 
 */
class Symbol {
    public:
        /**
         * @brief Construct a new wildcard symbol object.
         * 
         */
        Symbol();

        /**
         * @brief Construct a new Symbol object from a character.
         * 
         * @param symbol The character from which to create a symbol.
         */
        Symbol(char symbol);

        /**
         * @brief Compare two symbols for equality.
         * Symbol equality supports wildcards.
         * 
         * @param lhs a symbol,
         * @param rhs the symbol to compare it to.
         * @return true if the two symbols are equal or one of them is a wildcard.
         * @return false otherwise.
         */
        static bool compare(Symbol lhs, Symbol rhs);

        /**
         * @brief Convert the symbol to a regular string
         * 
         * @return a string with the contents of the symbol.
         */
        std::string toString();
        
        /**
         * @brief Determines if a symbol is a wildcard
         * 
         * @return true if this symbol is a wildcard
         * @return false otherwise
         */
        bool isWildcard();

    private:
        char internalSymbol;
        bool wildcard;
};
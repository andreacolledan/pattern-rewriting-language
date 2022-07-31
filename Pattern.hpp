#pragma once

#include "Symbol.hpp"
#include "Match.hpp"
#include "Orientation.hpp"

#include <vector>

class Rule; //forward declaration

/**
 * @brief Implements a n⨉m pattern of symbols and wildcards.
 * 
 * Note: when visiting the internal 2D symbol array, the height of the pattern
 * is the first dimension, the width of the pattern is the second dimension,
 * like when working with matrices.
 * 
 * Note: by sub-pattern we mean a region of the pattern.
 * 
 */
class Pattern {
    public:

        /**
         * @brief Construct a new empty Pattern object
         * 
         */
        Pattern();

        /**
         * @brief Construct a new Pattern object from a 2d array of symbols
         * 
         * @param pattern the 2d vector containing the symbols of the pattern
         */
        Pattern(std::vector<std::vector<Symbol>> pattern);

        /**
         * @brief Search this pattern for occurrences of pattern p.
         * 
         * @param pattern The pattern to look for.
         * @return a vector of matches representing where and in which orientation pattern occurs as a sub-pattern of this pattern.
         */
        std::vector<Match> search(Pattern& pattern);

        /**
         * @brief Replaces the sub-pattern identified by position in this pattern with the provided pattern.
         * 
         * @param pattern the pattern to replace with,
         * @param position the position where to replace the sub-pattern
         * @return true if the replacement was succesful
         * @return false if the provided pattern does not fit in this pattern
         */
        bool replace(Pattern& pattern, Match position);

        /**
         * @brief Search this pattern for occurrences of the sub-pattern that rule r can be applied to,
         * choose one such occurrence randomly and apply r to it.
         * 
         * @param rule the rule to apply.
         * @return true if the pattern has been changed as a result of the application of the rule
         * @return false if the rule did non match any sub-pattern of the pattern
         */
        bool apply(Rule& rule);

        /**
         * @brief Print this pattern in a compact way.
         * 
         */
        void prettyPrint();

        std::string toString();

        /**
         * @brief Check if this pattern is the empty (trivial) pattern
         * 
         * @return true if this pattern is empty
         * @return false if this pattern is not empty
         */
        bool isEmpty();

        /**
         * @brief Check if this pattern contains one or more wildcard symbols
         * 
         * @return true if this pattern contains at least one wildcard symbol
         * @return false if this pattern contains no wildcard symbol
         */
        bool containsWildcard();

        /**
         * @brief Get a list of all distinct symbols in the pattern which are not wildcards
         * 
         * @return a list of all distinct symbols in the pattern
         */
        std::vector<Symbol> getSymbols();

        /**
         * @brief Check if this pattern is entirely made up of symbols from symbols and wildcards
         * 
         * @param symbols the list of symbols that may make up this pattern
         * @return true if this pattern is exclusively made up of symbols from symbols
         * @return false if at least one symbol in this pattern does not come from symbols
         */
        bool madeUpOf(std::vector<Symbol> symbols);

        /**
         * @brief Check if the pattern is actually rectangular (i.e. all rows are of length width)
         * 
         * @return true if the pattern is rectangular
         * @return false if at least two rows differ in length
         */
        bool isRectangular();

        int getHeight();

        int getWidth();

    private:
        int width, height;
        std::vector<std::vector<Symbol>> internalPattern;

        /**
         * @brief Compare a sub-pattern of this pattern with a second pattern for equality.
         * 
         * @param pattern the pattern to compare to
         * @param vOffset the vertical offset in this pattern where the sub-pattern starts
         * @param hOffset the horizontal offset in this pattern where the sub-pattern starts
         * @param orientation the orientation of the sub-pattern 
         * @return true if this pattern's sub-pattern matches pattern
         * @return false if this pattern's sub-pattern and rhs differ in at least one symbol
         */
        bool compare(Pattern& pattern, int vOffset, int hOffset, Orientation orientation);

        /**
         * @brief Check if symbol appears among symbols
         * 
         * @param symbol the symbol to be checked for belonging
         * @param symbols the list of symbols that it may belong to
         * @return true if symbol occurs in symbols
         * @return false if symbol does not occur in symbols
         */
        static bool symbolIsIn(Symbol symbol, std::vector<Symbol> symbols);
};
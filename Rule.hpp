#pragma once

#include "Pattern.hpp"

/**
 * @brief Implements a rewriting rule from a pattern to another.
 * 
 */
class Rule {
    public:
        /**
         * @brief Construct a new Rule object which rewrites the lhs pattern to the ths pattern.
         * 
         * @param lhs the pattern to rewrite,
         * @param rhs the pattern to rewrite it to.
         */
        Rule(Pattern lhs, Pattern rhs);

        /**
         * @brief Get the left-hand side of the rewrite rule
         * 
         * @return the left-hand side of the rewrite rule 
         */
        Pattern getLhs();

        /**
         * @brief Get the right-hand side of the rewrite rule
         * 
         * @return the right-hand side of the rewrite rule 
         */
        Pattern getRhs();
        
    private:
        Pattern lhs, rhs;
};
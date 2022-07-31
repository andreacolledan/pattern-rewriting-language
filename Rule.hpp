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
         * @brief Construct a new exhaustible Rule object which rewrites the lhs pattern to the ths pattern.
         * 
         * @param lhs the pattern to rewrite,
         * @param rhs the pattern to rewrite it to.
         * @param uses the limit tot the number of times the rule can be used
         */
        Rule(Pattern lhs, Pattern rhs, int uses);

        /**
         * @brief Get the left-hand side of the rewrite rule
         * 
         * @return the left-hand side of the rewrite rule 
         */
        Pattern& getLhs();

        /**
         * @brief Get the right-hand side of the rewrite rule
         * 
         * @return the right-hand side of the rewrite rule 
         */
        Pattern& getRhs();
        
        /**
         * @brief Determine if a rule can be used or is exhausted
         * 
         * @return true if the rule has still at least a use left
         * @return false if the rule is exhausted
         */
        bool canBeUsed();

        /**
         * @brief Consume a use of this rule
         * 
         */
        void consume();

        int getUses();
        
    private:
        Pattern lhs, rhs;
        int uses;
};
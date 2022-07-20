#include "Rule.hpp"

Rule::Rule(Pattern lhs, Pattern rhs) : lhs(lhs), rhs(rhs) {}

Pattern Rule::getLhs() {
    return lhs;
}

Pattern Rule::getRhs() {
    return rhs;
}
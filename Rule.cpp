#include "Rule.hpp"

Rule::Rule(Pattern lhs, Pattern rhs) : lhs(lhs), rhs(rhs), uses(-1) {}

Rule::Rule(Pattern lhs, Pattern rhs, int uses) : lhs(lhs), rhs(rhs), uses(uses) {}

Pattern Rule::getLhs() {
    return lhs;
}

Pattern Rule::getRhs() {
    return rhs;
}

bool Rule::canBeUsed() {
    return uses != 0;
    /* Note that we have != 0 and not >0. This is because unlimited rules are
            modeled as having -1 uses. This way, they can be consumed any
            number of times without ever crossing 0 */
}

void Rule::consume() {
    uses--;
}
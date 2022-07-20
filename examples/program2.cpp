#include "Rule.hpp"

const Symbol WATER = Symbol('.');
const Symbol CLAND = Symbol('@');

Pattern pattern1 = Pattern(new Symbol*[10] {
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, CLAND, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, CLAND, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    }, 10, 10);
Pattern pattern2 = Pattern(new Symbol*[3] {
    new Symbol[3] {WATER, WATER, WATER},
    new Symbol[3] {WATER, CLAND, WATER},
    new Symbol[3] {WATER, WATER, WATER}
    }, 3, 3);
Pattern pattern3 = Pattern(new Symbol*[3] {
    new Symbol[3] {WATER, WATER, WATER},
    new Symbol[3] {WATER, WATER, CLAND},
    new Symbol[3] {WATER, WATER, WATER}
    }, 3, 3);

Rule ruleMove = Rule(pattern2, pattern3);
const int numberOfRules = 1;

Pattern start = pattern1;
Rule ruleSet[numberOfRules] = {ruleMove};
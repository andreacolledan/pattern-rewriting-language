#include "Rule.hpp"

const Symbol WATER = Symbol('.');
const Symbol CURSOR = Symbol('@');

Pattern pattern1 = Pattern(new Symbol*[10] {
    new Symbol[10] {CURSOR, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER},
    new Symbol[10] {WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, WATER, CURSOR},
    }, 10, 10);
Pattern pattern2 = Pattern(new Symbol*[1] {
    new Symbol[2] {CURSOR, WATER}
    }, 1, 2);
Pattern pattern3 = Pattern(new Symbol*[1] {
    new Symbol[2] {WATER, CURSOR}
    }, 1, 2);
Pattern pattern4 = Pattern(new Symbol*[1] {
    new Symbol[2] {CURSOR, CURSOR}
    }, 1, 2);
Pattern pattern5 = Pattern(new Symbol*[1] {
    new Symbol[2] {WATER, WATER}
    }, 1, 2);

Rule ruleMove = Rule(pattern2, pattern3);
Rule ruleElim = Rule(pattern4, pattern5);
const int numberOfRules = 2;

Pattern start = pattern1;
Rule ruleSet[numberOfRules] = {ruleMove, ruleElim};
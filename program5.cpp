#include "Rule.hpp"

const Symbol ROCK = Symbol('.');
const Symbol SEED = Symbol('@');

Pattern pattern1 = Pattern(new Symbol*[10] {
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    new Symbol[10] {ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK, ROCK},
    }, 10, 10);
Pattern pattern2 = Pattern(new Symbol*[1] {
    new Symbol[1] {ROCK}
    }, 1, 1);
Pattern pattern3 = Pattern(new Symbol*[1] {
    new Symbol[1] {SEED}
    }, 1, 1);

Rule ruleElim = Rule(pattern2, pattern3, 5);
const int numberOfRules = 1;

Pattern start = pattern1;
Rule ruleSet[numberOfRules] = {ruleElim};
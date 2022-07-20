#include "Pattern.hpp"
#include "Rule.hpp"

#include <iostream>

Pattern::Pattern(Symbol** p, int h, int w) : width(w), height(h), internalPattern(p) {}

bool Pattern::compare(Pattern p, int vOffset, int hOffset, Orientation o) {
    if ((o == Orientation::East || o == Orientation::West) && (width < p.width + hOffset || height < p.height + vOffset)) {
        return false; // p does not fit in this pattern
    } else if ((o == Orientation::North || o == Orientation::South) && (width < p.height + hOffset || height < p.width + vOffset)) {
        return false; // p does not fit in this pattern (inverted dimensions)
    } else {
        for (int i = 0; i < p.height; i++) {
            for (int j = 0; j < p.width; j++) {
                Symbol comparandum = p.internalPattern[i][j];
                switch(o) {
                    case Orientation::East: {
                        if (!Symbol::compare(internalPattern[vOffset + i][hOffset + j], comparandum)) {
                            return false; // patterns are distinct if they differ on at least one position
                        } break;
                    }
                    case Orientation::North: {
                        if (!Symbol::compare(internalPattern[vOffset + (p.width - 1 - j)][hOffset + i], comparandum)) {
                            return false;
                        } break;
                    }
                    case Orientation::West: {
                        if (!Symbol::compare(internalPattern[vOffset + (p.height - 1 - i)][hOffset + (p.width - 1 - j)], comparandum)) {
                            return false;
                        } break;
                    }
                    case Orientation::South: {
                        if (!Symbol::compare(internalPattern[vOffset + j][hOffset + (p.height - 1 - i)], comparandum)) {
                            return false;
                        } break;
                    }
                }
            }
        }
        return true; // if all symbols are equal, patterns are equal
    }
}

std::vector<Match> Pattern::search(Pattern p) {
    std::vector<Match> matches;
    // for every possible placement of p on this
    for (int voff = 0; voff < height - (p.height - 1); voff++) {
        for (int hoff = 0; hoff < width - (p.width - 1); hoff++) {
            if(compare(p, voff, hoff, Orientation::East)) {
                matches.push_back(*new Match(voff, hoff, Orientation::East));
            }
            if(compare(p, voff, hoff, Orientation::West)) {
                matches.push_back(*new Match(voff, hoff, Orientation::West));
            }
        }
    }
    // for every possible placement of p on this (inverted dimensions)
    for (int voff = 0; voff < height - (p.width - 1); voff++) {
        for (int hoff = 0; hoff < width - (p.height - 1); hoff++) {
            if(compare(p, voff, hoff, Orientation::North)) {
                matches.push_back(*new Match(voff, hoff, Orientation::North));
            }
            if(compare(p, voff, hoff, Orientation::South)) {
                matches.push_back(*new Match(voff, hoff, Orientation::South));
            }
        }
    }
    return matches;
}

bool Pattern::replace(Pattern p, Match m) {
    int voff = m.getVerticalOffset();
    int hoff = m.getHorizontalOffset();
    Orientation o = m.getOrientation();
    if ((o == Orientation::East || o == Orientation::West) && (width < p.width + hoff || height < p.height + voff)) {
        return false; // p does not fit in this pattern
    } else if ((o == Orientation::North || o == Orientation::South) && (width < p.height + hoff || height < p.width + voff)) {
        return false; // p does not fit in this pattern (inverted dimensions)
    } else {
        for (int i = 0; i < p.height; i++) {
            for (int j = 0; j < p.width; j++) {
                Symbol candidate = p.internalPattern[i][j];
                if (!candidate.isWildcard()) { //wildcards on the rhs of a rule leave the pattern unchanged
                    switch(o) {
                        case Orientation::East : {
                            internalPattern[voff + i][hoff + j] = candidate;
                            break;
                        }
                        case Orientation::North : {
                            internalPattern[voff + (p.width - 1 - j)][hoff + i] = candidate;
                            break;
                        }
                        case Orientation::West : {
                            internalPattern[voff + (p.height - 1 - i)][hoff + (p.width - 1 - j)] = candidate;
                            break;
                        }
                        case Orientation::South : {
                            internalPattern[voff + j][hoff + (p.height - 1 - i)] = candidate;
                            break;
                        }
                    }
                }
            }
        }
        return true;
    }
}

bool Pattern::apply(Rule r) {
    std::vector<Match> matches = search(r.getLhs());
    int numOfMatches = matches.size();
    if(numOfMatches > 0) {
        //int randomIndex = (int) numOfMatches * (rand() / (RAND_MAX + 1.0)); //for better randomness
        int randomIndex = rand() % numOfMatches;
        replace(r.getRhs(), matches[randomIndex]);
        return true;
    } else {
        return false;
    }
}

void Pattern::prettyPrint() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << internalPattern[i][j].toString();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
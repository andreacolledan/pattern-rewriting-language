#include "Match.hpp"

Match::Match(int vo, int ho, Orientation o) : verticalOffset(vo), horizontalOffset(ho), orientation(o) {}

int Match::getVerticalOffset() {
    return verticalOffset;
}

int Match::getHorizontalOffset() {
    return horizontalOffset;
}

Orientation Match::getOrientation() {
    return orientation;
}

std::string Match::toString() {
    return "[" + std::to_string(verticalOffset) + ", " + std::to_string(horizontalOffset) + "]";
}
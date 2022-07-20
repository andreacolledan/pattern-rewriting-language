#pragma once

#include <string>

#include <Orientation.hpp>

/**
 * @brief This class represents the location of a match within a pattern,
 * which is uniquely identified by its position and its orientation.
 * 
 */
class Match {
    public:
        Match(int verticalOffset, int horizontalOffset, Orientation orientation);
        int getHorizontalOffset();
        int getVerticalOffset();
        Orientation getOrientation();
        std::string toString();
    private:
        const int verticalOffset, horizontalOffset;
        const Orientation orientation;
};
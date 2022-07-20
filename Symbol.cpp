#include "Symbol.hpp"

Symbol::Symbol() : internalSymbol(' '), wildcard(true) {}

Symbol::Symbol(char c) : internalSymbol(c), wildcard(false) {}


bool Symbol::compare(Symbol lhs, Symbol rhs) {
    // This implementation is faster on non-wildcard symbols
    if (lhs.internalSymbol == rhs.internalSymbol) {
        return true;
    } else {
        return lhs.wildcard || rhs.wildcard;
    }
}

std::string Symbol::toString() {
    return std::string(1, internalSymbol);
}

bool Symbol::isWildcard() {
    return wildcard;
}
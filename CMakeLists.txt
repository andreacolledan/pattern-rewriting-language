cmake_minimum_required(VERSION 3.0.0)
project(PatternMatching VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()


set(SOURCES main.cpp Match.cpp Match.hpp Pattern.cpp Pattern.hpp Rule.cpp Rule.hpp Symbol.cpp Symbol.hpp Orientation.hpp)
add_executable(PatternMatching ${SOURCES})
target_include_directories(PatternMatching PRIVATE .)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


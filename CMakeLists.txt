cmake_minimum_required(VERSION 3.0.0)
project(PatternMatching VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

set(SOURCES main.cpp Match.hpp Match.cpp Pattern.hpp Pattern.cpp Rule.hpp Rule.cpp Symbol.hpp Symbol.cpp Cartridge.hpp Cartridge.cpp Orientation.hpp)
add_executable(PRL ${SOURCES})
target_include_directories(PRL PRIVATE ${PROJECT_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


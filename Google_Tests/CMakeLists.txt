cmake_minimum_required(VERSION 3.24)

# 'Google_test' is the subproject name
project(Google_Tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(COPY ../distances.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run
        ../BruteForce.hpp ../BruteForce.cpp testBruteForce.cpp
        ../FileParser.hpp ../FileParser.cpp testFileParser.cpp
        ../Genetic.hpp ../Genetic.cpp testGenetic.cpp
        ../MatrixManager.hpp ../MatrixManager.cpp testMatrixManager.cpp
        ../PermutationGenerator.hpp ../PermutationGenerator.cpp testPermutationGenerator.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main gmock gmock_main)
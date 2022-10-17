cmake_minimum_required(VERSION 3.24)
project(cop4534-p3)

set(CMAKE_CXX_STANDARD 14)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/distances.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(cop4534-p3 main.cpp PermutationGenerator.cpp PermutationGenerator.hpp MatrixManager.cpp MatrixManager.hpp Genetic.cpp Genetic.hpp BruteForce.cpp BruteForce.hpp FileParser.cpp FileParser.hpp)

add_subdirectory(Google_Tests)
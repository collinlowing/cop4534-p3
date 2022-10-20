/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.hpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#ifndef COP4534_P3_PERMUTATIONGENERATOR_HPP
#define COP4534_P3_PERMUTATIONGENERATOR_HPP

#include "string"
#include <iostream>
#include <vector>

class PermutationGenerator {
private:
    std::string distancesFileName = "distance.txt";
    std::vector<std::vector<int>> permutations;
    std::vector<int> nextPermutation;
public:
    std::vector<int> generateAllPermutation(std::vector<int> &now, std::vector<int> next);

    static void printVector(const std::vector<int> &vect);

    std::vector<std::vector<int>> &getPermutations();

    std::vector<int> getNextPermutation(std::vector<int>& route);
};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP

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
public:
    void bruteForcePermutation(std::vector<int> &now, std::vector<int> next);

    static void printVector(const std::vector<int> &vect);

    std::vector<std::vector<int>> &getPermutations();
};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP

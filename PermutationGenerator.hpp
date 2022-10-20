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
    std::vector<int> perm;
public:
    PermutationGenerator(std::vector<int>& perm);

    static void printVector(const std::vector<int> &vect);

    std::vector<int> getNextPermutation();

    void swap(int a, int b);
};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP

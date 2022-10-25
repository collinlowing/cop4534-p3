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
    int numOfCities;
    int *perm;
public:
    PermutationGenerator(int *perm, int numOfCities);

    static void printVector(std::vector<int>& vect);

    std::vector<int>& getNextPermutation();

    void swap(int a, int b);

    static int getNumOfPermutations(int numOfCities);


};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP

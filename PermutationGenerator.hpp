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
    int numOfCities;
    int generationSize;
    int numOfGenerations;
    double mutationPercentage;
public:
    //PermutationGenerator(int numOfCities, int generationSize, int numOfGenerations, double mutationPercentage);
    //int *getNextPermutation(int (*s), int arrayLength);

    //void printS(int *s, int size);

    void vectorPermutation(std::vector<int> &now, std::vector<int> next);

    static void printVector(const std::vector<int> &vect);
};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP

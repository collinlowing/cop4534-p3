/***************************************************************
  Student Name: Collin Lowing
  File Name: BruteForce.hpp
  Project 3

  Attempts to find the optimal traversal with iterative algorithms.
***************************************************************/

#ifndef COP4534_P3_BRUTEFORCE_HPP
#define COP4534_P3_BRUTEFORCE_HPP

#include <cfloat>
#include "PermutationGenerator.hpp"
#include "MatrixManager.hpp"

class BruteForce {
private:
    int numOfCities;
    MatrixManager mm;
public:
    BruteForce(int numOfCities);
    std::vector<int> performBruteForce();
};


#endif //COP4534_P3_BRUTEFORCE_HPP

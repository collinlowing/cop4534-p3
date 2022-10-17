/***************************************************************
  Student Name: Collin Lowing
  File Name: Genetic.hpp
  Project 3

  Attempts to find the optimal traversal with genetic algorithm
***************************************************************/

#ifndef COP4534_P3_GENETIC_HPP
#define COP4534_P3_GENETIC_HPP

#include "PermutationGenerator.hpp"
#include "MatrixManager.hpp"

class Genetic {
private:
    int numOfCities;
    int generationSize;
    int numOfGenerations;
    double mutationPercentage;
public:
    Genetic(int numOfCities, int generationSize, int numOfGenerations, double mutationPercentage);
    std::vector<int> performGenetic();
    std::vector<std::vector<int>> mergeMatrix(std::vector<std::vector<int>> vectorA, std::vector<std::vector<int>> vectorB);
    std::vector<int> mutateRoute(std::vector<int> route);
};


#endif //COP4534_P3_GENETIC_HPP

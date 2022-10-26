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
#include <random>

class Genetic {
private:
    int numOfCities;
    int generationSize;
    int numOfGenerations;
    double mutationPercentage;
    MatrixManager mm;
public:
    Genetic(int numOfCities, int generationSize, int numOfGenerations, double mutationPercentage);

    void performGenetic();

    int *mutateRoute(int *route);

    static int getRandomIndex(int min, int max);
};


#endif //COP4534_P3_GENETIC_HPP

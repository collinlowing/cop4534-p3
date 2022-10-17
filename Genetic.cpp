/***************************************************************
  Student Name: Collin Lowing
  File Name: Genetic.cpp
  Project 3

  Attempts to find the optimal traversal with genetic algorithm
***************************************************************/

#include "Genetic.hpp"

Genetic::Genetic(int numOfCities, int generationSize, int numOfGenerations, double mutationPercentage) {
    this->numOfCities = numOfCities;
    this->generationSize = generationSize;
    this->numOfGenerations = numOfGenerations;
    this->mutationPercentage = mutationPercentage;
}

std::vector<int> Genetic::performGenetic() {
    return std::vector<int>();
}

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
    //PermutationGenerator pg;
    std::vector<int> initialRoute;
    std::vector<int> perm = {0};
    std::vector<double> distances = {};

    // initialize first city route
    for (int i = 1; i < numOfCities; i++) {
        initialRoute.push_back(i);
    }

    // initialize optimal route with first route
    std::vector<int> optimalRoute = initialRoute;

    return std::vector<int>();
}

std::vector<std::vector<int>>
Genetic::mergeMatrix(std::vector<std::vector<int>> vectorA, std::vector<std::vector<int>> vectorB) {
    for (auto route: vectorB) {
        vectorA.push_back(route);
    }

    return vectorA;
}

std::vector<int> Genetic::mutateRoute(std::vector<int> route) {
    // get random index excluding start and end as that is always 0
    int index1 = Genetic::getRandomIndex(1, route.size() - 1);

    // get the nextPermutation index
    int index2;
    // index must be different than first index
    do {
        index2 = Genetic::getRandomIndex(1, route.size() - 1);
    } while (index1 == index2);

    // swaps the two random indexes
    std::swap(route.at(index1), route.at(index2));

    return route;
}

int Genetic::getRandomIndex(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // input seed into generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}



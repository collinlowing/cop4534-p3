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
    std::vector<int> route = {};
    std::vector<int> currentRoute = {0};
    std::vector<double> distances = {};
    double smallestDistance;
    std::vector<int> smallestRoute = {};
    std::vector<std::vector<int>> mutations;

    // initialize first city route
    for (int i = 1; i < numOfCities; i++) {
        route.push_back(i);
    }

    // initialize PermutationGenerator with initial route
    PermutationGenerator pg(route);

    // get adjacency matrix
    std::vector<std::vector<double>> distanceMatrix = MatrixManager::getMatrix(numOfCities, "distances.txt");

    // get distances for initial route
    for(int i = 0; i < currentRoute.size() - 1; i++) {
        int start = currentRoute.at(i);
        int next = currentRoute.at(i + 1);
        distances.push_back(distanceMatrix[start][next]);
    }

    // calculate distance for initial route
    double currentDistance = MatrixManager::addDistances(distances);

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    smallestRoute = currentRoute;

    for(int generationCount = 0; generationCount < numOfGenerations; generationCount++) {

        // generate new generation of routes
        for(int i = 0; i < generationSize; i++) {
            // get new permutation
            route = pg.getNextPermutation();

            // insert route into currentRoute with beginning and ending cities as 0
            for(int j = 1; j < currentRoute.size() - 1; j++) {
                currentRoute[i] = route[i];
            }

            // get distances for current route
            for(int j = 0; j < currentRoute.size() - 1; j++) {
                int start = currentRoute.at(i);
                int next = currentRoute.at(i+1);
                distances.push_back(distanceMatrix[start][next]);
            }

            // calculate distance for current route
            currentDistance = MatrixManager::addDistances(distances);

            // check if current distance is less than smallestRoute so far
            if(MatrixManager::isSmallerDistance(currentDistance, smallestDistance)) {
                smallestDistance = currentDistance;
                smallestRoute = currentRoute;
            }
        }
    }

    return smallestRoute;
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



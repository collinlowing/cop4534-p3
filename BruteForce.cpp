/***************************************************************
  Student Name: Collin Lowing
  File Name: BruteForce.cpp
  Project 3

  Attempts to find the optimal traversal with iterative algorithms.
***************************************************************/


#include "BruteForce.hpp"

BruteForce::BruteForce(int numOfCities) {
    this->numOfCities = numOfCities;
}

int [] BruteForce::performBruteForce() {
    int route[numOfCities];
    int currentRoute[numOfCities + 1];
    double smallestDistance;
    int smallestRoute[numOfCities + 1];

    // initialize cities
    for(int i = 1; i < numOfCities; i++) {
        route[i - 1] = i;
    }

    currentRoute[0] = 0; // start with city 0
    // append current route with initial route
    for(int i = 1; i < numOfCities; i++) {
        currentRoute[i] = route[i - 1];
    }
    currentRoute[numOfCities] = 0; // end with starting city. always 0

    // pass first route to PermutationGenerator object
    PermutationGenerator pg(route, numOfCities);

    // get the number of permutations to perform
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numOfCities - 1);

    // get adjacency matrix
    mm.generateAdjacencyMatrix(numOfCities, "distances.txt");

    // get distances for initial route
    double currentDistance = mm.computeDistance(currentRoute, numOfCities);

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    std::copy(currentRoute, currentRoute + (numOfCities + 1),smallestRoute);

    for(int permutationCount = 0; permutationCount < numOfPermutations - 1; permutationCount++) {
        // get new permutation
        route = pg.getNextPermutation();

        // insert route into currentRoute with beginning and ending cities as 0
        for(int i = 1; i < currentRoute.size() - 1; i++) {
            currentRoute[i] = route[i];
        }

        // get distances for current route
        for(int i = 0; i < currentRoute.size() - 1; i++) {
            int start = currentRoute.at(i);
            int next = currentRoute.at(i+1);
            currentDistance += distanceMatrix[start][next];
        }

        // check if current distance is less than smallestRoute so far
        if(MatrixManager::isSmallerDistance(currentDistance, smallestDistance)) {
            smallestDistance = currentDistance;
            smallestRoute = currentRoute;
        }
    }

    PermutationGenerator::printVector(smallestRoute);
    std::cout << "optimal route distance total: " << smallestDistance << std::endl;

    return smallestRoute;
}


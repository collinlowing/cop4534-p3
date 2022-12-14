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

double BruteForce::performBruteForce() {
    int *route = new int[MAX_CITIES];
    int *currentRoute = new int[MAX_CITIES + 1];
    double smallestDistance;
    int *smallestRoute = new int[MAX_CITIES + 1];

    // initialize cities
    for (int i = 1; i < numOfCities; i++) {
        route[i - 1] = i;
    }

    currentRoute[0] = 0; // start with city 0

    // append current route with initial route
    for (int i = 1; i < numOfCities; i++) {
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
    double currentDistance = mm.computeDistance(currentRoute, numOfCities + 1);

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    for(int i = 0; i < numOfCities; i++) {
        smallestRoute[i] = currentRoute[i];
    }

    for (int permutationCount = 0; permutationCount < numOfPermutations - 1; permutationCount++) {
        // get new permutation
        route = pg.getNextPermutation();

        // insert route into currentRoute with beginning and ending cities as 0
        for (int i = 1; i < numOfCities; i++) {
            currentRoute[i] = route[i - 1];
        }

        // get distances for current route
        currentDistance = mm.computeDistance(currentRoute, numOfCities + 1);

        // check if current distance is less than smallestRoute so far
        if (MatrixManager::isSmallerDistance(currentDistance, smallestDistance)) {
            smallestDistance = currentDistance;
            smallestRoute = currentRoute;
        }
    }

    pg.printPermutation(smallestRoute, numOfCities + 1);
    std::cout << "optimal route distance total: " << smallestDistance << std::endl;

    delete[] route;
    delete[] currentRoute;

    return smallestDistance;
}


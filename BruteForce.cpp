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

std::vector<int> BruteForce::performBruteForce() {
    std::vector<int> route = {};
    std::vector<double> distances = {};
    std::vector<int> currentRoute = {0};
    double smallestDistance = DBL_MAX;
    std::vector<int> smallestRoute = {};

    // initialize cities
    for(int i = 1; i < numOfCities; i++) {
        route.push_back(i);
    }

    // append current route with initial route
    currentRoute.insert(currentRoute.end(), route.begin(), route.end());
    currentRoute.push_back(0); // end with starting city. always 0

    // pass first route to PermutationGenerator object
    PermutationGenerator pg(route);

    // get the number of permutations to perform
    int numOfPermutations = pg.getNumOfPermutations(numOfCities);

    // get adjacency matrix
    std::vector<std::vector<double>> distanceMatrix = MatrixManager::getMatrix(numOfCities, "distances.txt");

    for(int permutationCount = 0; permutationCount < numOfPermutations; permutationCount++) {
        // get distances for current route
        for(int i = 0; i < currentRoute.size() - 1; i++) {
            int start = currentRoute.at(i);
            int next = currentRoute.at(i+1);
            distances.push_back(distanceMatrix[start][next]);
        }

        // calculate distance for initial route
        double currentDistance = MatrixManager::addDistances(distances);

        // check if current distance is less than smallestRoute so far
        if(MatrixManager::isSmallerDistance(currentDistance, smallestDistance)) {
            smallestDistance = currentDistance;
            smallestRoute = currentRoute;
        }

        // get new permutation
        route = pg.getNextPermutation();

        // clear current route
        currentRoute.clear();
        // initialize new route permutation
        currentRoute.push_back(0); // start with 0
        currentRoute.resize(route.size() + 1);
        currentRoute.insert(currentRoute.end(), route.begin(), route.end());
        currentRoute.push_back(0); // end with 0
    }

    PermutationGenerator::printVector(smallestRoute);
    std::cout << "optimal route distance total: " << smallestDistance << std::endl;

    return smallestRoute;
}


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
    double smallestDistance;
    std::vector<int> smallestRoute = {};

    // initialize cities
    for(int i = 1; i < numOfCities; i++) {
        route.push_back(i);
    }

    // initialize vector size for starting and ending cities not in route
    currentRoute.resize(route.size() + 2);

    // append current route with initial route
    for(int i = 1; i < route.size(); i++) {
        currentRoute[i] = route[i];
    }
    currentRoute.push_back(0); // end with starting city. always 0

    // pass first route to PermutationGenerator object
    PermutationGenerator pg(route);

    // get the number of permutations to perform
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numOfCities - 1);

    // get adjacency matrix
    std::vector<std::vector<double>> distanceMatrix = MatrixManager::getMatrix(numOfCities, "distances.txt");

    // get distances for initial route
    double currentDistance = 0.0;
    for(int i = 0; i < currentRoute.size() - 1; i++) {
        int start = currentRoute.at(i);
        int next = currentRoute.at(i + 1);
        currentDistance += distanceMatrix[start][next];
    }

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    smallestRoute = currentRoute;

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

    PermutationGenerator::printVector(smallestRoute);
    std::cout << "optimal route distance total: " << smallestDistance << std::endl;

    return smallestRoute;
}


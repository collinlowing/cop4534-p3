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
    PermutationGenerator pg;
    std::vector<int> initialRoute;
    std::vector<int> perm = {0};
    std::vector<double> distances = {};

    // initialize cities
    for(int i = 1; i < numOfCities; i++) {
        initialRoute.push_back(i);
    }

    // get all possible permutations
    pg.generateAllPermutation(initialRoute, perm);
    std::vector<std::vector<int>> permutationMatrix = pg.getPermutations();

    // get distances
    std::vector<std::vector<double>> distanceMatrix = MatrixManager::getMatrix(numOfCities, "distances.txt");

    // make a vector with all distances of permutations
    for(int i = 0; i < permutationMatrix.size(); i++) {
        distances.push_back(0);
        for(int j = 0; j < permutationMatrix[i].size() - 1; j++) {
            int current = permutationMatrix[i][j];
            int next = permutationMatrix[i][j+1];
            distances[i] += distanceMatrix[current][next];
        }
    }

    // get smallest distance
    double smallestDistance = DBL_MAX;
    int index = 0;
    int smallestIndex;

    for(auto d : distances) {
        if(MatrixManager::isSmallerDistance(d, smallestDistance)) {
            smallestDistance = d;
            smallestIndex = index;
        }
        index++;
    }
    PermutationGenerator::printVector(permutationMatrix[smallestIndex]);
    std::cout << "optimal route distance total: " << smallestDistance << std::endl;

    return permutationMatrix[smallestIndex];
}


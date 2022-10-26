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

int *Genetic::performGenetic() {
    int *route = new int[numOfCities];
    int *currentRoute = new int[numOfCities + 1];
    double smallestDistance;
    int *smallestRoute = new int[numOfCities + 1];

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
    double currentDistance = mm.computeDistance(currentRoute, numOfCities);

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    std::copy(currentRoute, currentRoute + (numOfCities + 1), smallestRoute);

    for (int permutationCount = 0; permutationCount < numOfPermutations - 1; permutationCount++) {
        // get new permutation
        route = pg.getNextPermutation();

        // insert route into currentRoute with beginning and ending cities as 0
        for (int i = 1; i < numOfCities - 1; i++) {
            currentRoute[i] = route[i];
        }

        // get distances for current route
        currentDistance = mm.computeDistance(currentRoute, numOfCities);

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

    return smallestRoute;
}


/*
std::vector<std::vector<int>>
Genetic::mergeMatrix(std::vector<std::vector<int>> vectorA, std::vector<std::vector<int>> vectorB) {
    for (auto route: vectorB) {
        vectorA.push_back(route);
    }

    return vectorA;
}
*/


int* Genetic::mutateRoute(int* route) {
    // get random index excluding start and end as that is always 0
    int index1 = Genetic::getRandomIndex(1, numOfCities - 1);

    // get the nextPermutation index
    int index2;
    // index must be different than first index
    do {
        index2 = Genetic::getRandomIndex(1, numOfCities - 1);
    } while (index1 == index2);

    // swaps the two random indexes
    std::swap(route[index1], route[index2]);

    return route;
}

int Genetic::getRandomIndex(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // input seed into generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}

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

double Genetic::performGenetic() {
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

    // get adjacency matrix
    mm.generateAdjacencyMatrix(numOfCities, "distances.txt");

    // get distances for initial route
    double currentDistance = mm.computeDistance(currentRoute, numOfCities + 1);

    // initialize the smallest route with first route
    smallestDistance = currentDistance;
    for(int i = 0; i < numOfCities; i++) {
        smallestRoute[i] = currentRoute[i];
    }

    // get the number of permutations to mutate
    int numOfMutations = generationSize * mutationPercentage;

    // counter for mutations created
    int mutationCounter = 0;

    // loop for the number of generations to perform
    for(int generationCount = 0; generationCount < numOfGenerations; generationCount++) {
        for(int permCount = 0; permCount < generationSize - 1; permCount++) { // excluding 1 elite
            // get mutatedRoute
            if (mutationCounter < numOfMutations) {
                route = mutateRoute(route);
                numOfMutations++;
            }
            else {
                // get new permutation
                route = pg.getNextPermutation();
            }

            // insert route into currentRoute with beginning and ending cities as 0
            for (int i = 1; i < numOfCities; i++) {
                currentRoute[i] = route[i - 1];
            }

            // get distances for current route
            currentDistance = mm.computeDistance(currentRoute, numOfCities + 1);

            // compare with elite
            // check if current distance is less than smallest route so far
            if (MatrixManager::isSmallerDistance(currentDistance, smallestDistance)) {
                smallestDistance = currentDistance;
                smallestRoute = currentRoute;
            }
        }
        // reset mutations
        numOfMutations = 0;
    }

    pg.printPermutation(smallestRoute, numOfCities + 1);
    std::cout << "route distance total: " << smallestDistance << std::endl;

    // clean up memory
    delete[] route;
    delete[] currentRoute;

    return smallestDistance;
}

int* Genetic::mutateRoute(int* route) {
    // get random index excluding start and end as that is always 0
    int index1 = Genetic::getRandomIndex(1, numOfCities - 2);

    // get the nextPermutation index
    int index2;

    // index must be different than first index
    do {
        index2 = Genetic::getRandomIndex(1, numOfCities - 2);
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

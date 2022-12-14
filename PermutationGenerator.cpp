/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.cpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#include "PermutationGenerator.hpp"

PermutationGenerator::PermutationGenerator(int *perm, int numOfCities) {
    this->perm = perm;
    this->numOfCities = numOfCities;
}

int *PermutationGenerator::getNextPermutation() {
    int routeSize = numOfCities - 1;

    int m, k, p, q;
    m = routeSize - 2;
    while (perm[m] > perm[m + 1]) {
        m = m - 1;
    }
    k = routeSize - 1;
    while (perm[m] > perm[k]) {
        k = k - 1;
    }
    swap(m, k);
    p = m + 1;
    q = routeSize - 1;
    while (p < q) {
        swap(p, q);
        p++;
        q--;
    }
    // printPermutation(perm, routeSize); // used for testing
    return perm;
}

void PermutationGenerator::swap(int a, int b) {
    int temp = perm[a];
    perm[a] = perm[b];
    perm[b] = temp;
}

void PermutationGenerator::printPermutation(int *permutation, int size) {
    std::cout << "route: ";
    for (int i = 0; i < size; i++) {
        std::cout << permutation[i] << " ";
    }
    std::cout << std::endl;
}

int PermutationGenerator::getNumOfPermutations(int numOfCities) {
    int factorial = 1;

    if (numOfCities < 0) {
        std::cout << "the number of cities to permute must be 0 or greater" << std::endl;
        return -1;
    }

    for (int i = 1; i <= numOfCities; i++) {
        factorial *= i;
    }

    return factorial;
}
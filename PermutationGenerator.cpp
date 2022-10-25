/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.cpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#include "PermutationGenerator.hpp"

PermutationGenerator::PermutationGenerator(std::vector<int>& perm) {
    this->perm = perm;
}

std::vector<int>& PermutationGenerator::getNextPermutation() {
    int vectorSize = perm.size();

    int m, k, p , q;
    m = vectorSize - 2;
    while(perm[m] > perm[m+1])
    {
        m = m - 1;
    }
    k = vectorSize - 1;
    while(perm[m] > perm[k])
    {
        k = k - 1;
    }
    swap(m,k);
    p = m + 1;
    q = vectorSize - 1;
    while(p < q)
    {
        swap(p,q);
        p++;
        q--;
    }
    printVector(perm);
    return perm;
}

void PermutationGenerator::swap(int a, int b) {
    int temp = perm[a];
    perm[a] = perm[b];
    perm[b] = temp;
}

void PermutationGenerator::printVector(std::vector<int>& vect) {
    std::cout << "vector contains: ";
    for (int i: vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int PermutationGenerator::getNumOfPermutations(int numOfCities) {
    int factorial = 1;

    if(numOfCities < 0) {
        std::cout << "the number of cities to permute must be 0 or greater" << std::endl;
        return -1;
    }

    for(int i = 1; i <= numOfCities; i++) {
        factorial *= i;
    }

    return factorial;
}
/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.cpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#include "PermutationGenerator.hpp"


/*
PermutationGenerator::PermutationGenerator(int numOfCities, int generationSize, int numOfGenerations,
                                           double mutationPercentage) {
    this->numOfCities = numOfCities;
    this->generationSize = generationSize;
    this->numOfGenerations = numOfGenerations;
    this->mutationPercentage = mutationPercentage;
}
*/

/*
int *PermutationGenerator::getNextPermutation(int (*s), int arrayLength) {
    int m, k, p, q, i;
    m = arrayLength - 2;
    while (s[m] > s[m + 1]) {
        m = m - 1;
    }
    k = arrayLength - 1;
    while (s[m] > s[k]) {
        k = k - 1;
    }
    std::swap(m, k);
    p = m + 1;
    q = arrayLength - 1;
    while (p < q) {
        std::swap(p, q);
        p++;
        q--;
    }
    printS(s, arrayLength);
    return s;
}
*/

/*
void PermutationGenerator::printS(int (*s), int size) {
    for (int i = 0; i < size; i++) {
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;
}
*/

/*void PermutationGenerator::vectorPermutation(std::vector<int>& route, std::vector<int>& perm) {
    if(route.empty()) {
        printVector(route);
        return;
    }

    for(int i = 0; i < route.size(); i++) {
        std::vector<int> route2 = route;
        std::vector<int>::iterator it;

        it = route2.begin() + i;

        route2.erase(it);

        std::vector<int> perm2 = perm;

        perm2.push_back(route.at(i));

        vectorPermutation(route2, perm2);
    }

}*/

void PermutationGenerator::vectorPermutation(std::vector<int> &now, std::vector<int> next) {
    int size = now.size();
    if (size > 0) {
        for (int count = 0; count < size; count++) {
            std::vector<int> vt;

            typename std::vector<int>::const_iterator it = now.begin();
            for (int count1 = 0; count1 < size; count1++) {
                if (count1 == count) {
                    it++;
                    continue;
                } else {
                    vt.push_back(*it);
                }
                it++;
            }

            typename std::vector<int>::const_iterator it1 = now.begin();
            --it1;
            for (int cnt2 = 0; cnt2 <= count; ++cnt2) {
                ++it1;
            }

            next.push_back(*it1);
            vectorPermutation(vt, next);
            next.pop_back();
        }

    } else {
        PermutationGenerator::printVector(next);
    }
}


void PermutationGenerator::printVector(const std::vector<int> &vect) {
    std::cout << "vector contains: ";
    for (int i: vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

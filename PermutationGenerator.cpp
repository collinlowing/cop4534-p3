/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.cpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#include "PermutationGenerator.hpp"

// brute force method
void PermutationGenerator::bruteForcePermutation(std::vector<int> &now, std::vector<int> next) {
    int size = now.size();
    if (size > 0) {
        for (int count = 0; count < size; count++) {
            std::vector<int> vt;

            auto it = now.begin();
            for (int count1 = 0; count1 < size; count1++) {
                if (count1 == count) {
                    it++;
                    continue;
                } else {
                    vt.push_back(*it);
                }
                it++;
            }

            auto it1 = now.begin();
            --it1;
            for (int cnt2 = 0; cnt2 <= count; ++cnt2) {
                ++it1;
            }

            next.push_back(*it1);
            bruteForcePermutation(vt, next);
            next.pop_back();
        }

    } else {
        //PermutationGenerator::printVector(next);
        permutations.push_back(next);
    }
}


void PermutationGenerator::printVector(const std::vector<int> &vect) {
    std::cout << "vector contains: ";
    for (int i: vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> &PermutationGenerator::getPermutations() {
    return permutations;
}

//
// Created by cel on 10/13/22.
//

#include "gtest/gtest.h"
#include "../PermutationGenerator.hpp"

TEST(PermutationGeneratorTests, vectorPermutation) {
    PermutationGenerator pg;
    std::vector<int> vect = {1, 2, 3, 4, 5};
    std::vector<int> perm;
    pg.vectorPermutation(vect, perm);
    std::vector<std::vector<int>> permutations = pg.getPermutations();
    PermutationGenerator::printVector(permutations.front());
    PermutationGenerator::printVector(permutations.at(25));
}

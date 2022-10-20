//
// Created by cel on 10/13/22.
//

#include "gtest/gtest.h"
#include "../PermutationGenerator.hpp"

TEST(PermutationGeneratorTests, bruteForcePermutation) {
    std::vector<int> vect = {1, 2, 3, 4, 5};
    PermutationGenerator pg(vect);
    for(int i = 0; i < 119; i++) {
        pg.getNextPermutation();
    }
}

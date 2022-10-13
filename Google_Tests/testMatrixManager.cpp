//
// Created by cel on 10/13/22.
//

#include "gtest/gtest.h"
#include "../MatrixManager.hpp"

TEST(MatrixManagerTests, getPercentIdleTime) {
    int numOfCities = 5;
    std::vector<std::vector<double>> matrix = MatrixManager::getMatrix(numOfCities, "distances.txt");

    ASSERT_EQ(matrix.size(), 5);
    ASSERT_EQ(matrix[0].size(), 5);

    double firstDistance = 25.410000;

    EXPECT_EQ(matrix[0][0], firstDistance);

    double lastDistance = 27.920000;

    EXPECT_EQ(matrix[4][4], lastDistance);
}
//
// Created by cel on 10/13/22.
//

#include "gtest/gtest.h"
#include "../MatrixManager.hpp"

TEST(MatrixManagerTests, getMatrix) {
    int numOfCities = 5;
    MatrixManager mm;
    double** matrix;

    mm.generateAdjacencyMatrix(numOfCities, "distances.txt");

    matrix = mm.getMatrix();

    double firstDistance = 25.410000;

    EXPECT_EQ(matrix[0][0], firstDistance);

    double lastDistance = 27.920000;

    EXPECT_EQ(matrix[4][4], lastDistance);
}
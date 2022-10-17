//
// Created by cel on 10/13/22.
//

#include "gtest/gtest.h"
#include "../FileParser.hpp"

TEST(FileParserTests, getDistancesFromFile) {
    std::vector<double> distances = FileParser::getDistancesFromFile("distances.txt");

    EXPECT_EQ(distances.at(0), 25.410000);
    EXPECT_EQ(distances.at(1), 109.670000);
    EXPECT_EQ(distances.at(2), 88.340000);
    EXPECT_EQ(distances.at(3), 90.000000);
    EXPECT_EQ(distances.at(4), 116.690000);
    EXPECT_EQ(distances.at(5), 82.240000);
    EXPECT_EQ(distances.at(6), 39.780000);
    EXPECT_EQ(distances.at(7), 118.580000);
    EXPECT_EQ(distances.at(8), 94.620000);
    EXPECT_EQ(distances.at(9), 69.640000);

}

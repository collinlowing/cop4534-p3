/***************************************************************
  Student Name: Collin Lowing
  File Name: MatrixManager.cpp
  Project 3

  Data structure for matrix traversal map
***************************************************************/

#include "MatrixManager.hpp"

// is a smaller than b
bool MatrixManager::isSmallerDistance(double a, double b) {
    return a < b;
}

double MatrixManager::computeDistance(const int route[], int numOfCities) {
    double totalDistance = 0;
    totalDistance += distances[0][route[0]];
    for(int i = 1; i < numOfCities; i++) {
        totalDistance += distances[route[i - 1]][route[i]];
    }
    totalDistance += distances[route[numOfCities - 1]][0];

    return totalDistance;
}

void MatrixManager::generateAdjacencyMatrix(int numOfCities, std::string distancesFileName) {
    // get distances from file
    std::vector<double> allDistances = FileParser::getDistancesFromFile(distancesFileName);

    // set distance values into matrix
    int count = 0;
    for (auto & adjArray : distances) {
        for (auto & distance : adjArray) {
            distance = allDistances[count];
            count++;
        }
    }
}

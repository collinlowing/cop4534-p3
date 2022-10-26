/***************************************************************
  Student Name: Collin Lowing
  File Name: MatrixManager.cpp
  Project 3

  Data structure for matrix traversal map
***************************************************************/

#include "MatrixManager.hpp"

MatrixManager::MatrixManager() {
    // initializing matrix
    distances = new double *[20];

    for (int i = 0; i < 20; i++) {
        distances[i] = new double[20];
    }
}

// is a smaller than b
bool MatrixManager::isSmallerDistance(double a, double b) {
    return a < b;
}

double MatrixManager::computeDistance(const int *route, int numOfCities) {
    double totalDistance = 0;
    totalDistance += distances[0][route[0]];
    for (int i = 1; i < numOfCities; i++) {
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
    for (int i = 0; i < numOfCities; i++) {
        for (int j = 0; j < numOfCities; j++) {
            distances[i][j] = allDistances[count];
            count++;
        }
    }
}

// only used for testing
double **MatrixManager::getMatrix() {
    return distances;
}

MatrixManager::~MatrixManager() {
    // free memory
    for (int i = 0; i < 20; i++) {
        delete[] distances[i];
    }
    delete[] distances;
}
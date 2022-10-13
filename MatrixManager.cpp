/***************************************************************
  Student Name: Collin Lowing
  File Name: MatrixManager.cpp
  Project 3

  Data structure for matrix traversal map
***************************************************************/

#include "MatrixManager.hpp"

double MatrixManager::addDistances(std::vector<double> &routeDistances) {
    double sum = 0;

    for(double distance: routeDistances) {
        sum += distance;
    }

    return sum;
}

// is a smaller than b
bool MatrixManager::isSmallerDistance(double a, double b) {
    return a < b;
}

std::vector<std::vector<double>> MatrixManager::getMatrix(int numOfCities, std::string distancesFileName) {
    std::vector<std::vector<double>> matrix;

    // resize matrix to be numOfCities x numOfCities
    matrix.resize(numOfCities);
    for(auto & vector : matrix) {
        vector.resize(numOfCities);
    }

    // get distances from file
    std::vector<double> distances = FileParser::getDistancesFromFile(distancesFileName);

    if(distances.empty()) {
        return matrix;
    }

    // set distance values into matrix
    int count = 0;
    for (auto & vector : matrix) {
        for (auto & distance : vector) {
            distance = distances[count];
            count++;
        }
    }
    return matrix;
}
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


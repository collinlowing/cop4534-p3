/***************************************************************
  Student Name: Collin Lowing
  File Name: MatrixManager.hpp
  Project 3

  Data structure for matrix traversal map
***************************************************************/

#ifndef COP4534_P3_MATRIXMANAGER_HPP
#define COP4534_P3_MATRIXMANAGER_HPP

#include <vector>
#include "FileParser.hpp"

class MatrixManager {
private:
    double **distances;
public:
    MatrixManager();

    static bool isSmallerDistance(double a, double b);

    void generateAdjacencyMatrix(int numOfCities, std::string distancesFileName);

    double computeDistance(const int *route, int numOfCities);

    double **getMatrix();

    ~MatrixManager();
};


#endif //COP4534_P3_MATRIXMANAGER_HPP

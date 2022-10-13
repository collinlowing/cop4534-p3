/***************************************************************
  Student Name: Collin Lowing
  File Name: MatrixManager.hpp
  Project 3

  Data structure for matrix traversal map
***************************************************************/

#ifndef COP4534_P3_MATRIXMANAGER_HPP
#define COP4534_P3_MATRIXMANAGER_HPP

#include <vector>

class MatrixManager {
public:
    static double addDistances(std::vector<double>& route);

    static bool isSmallerDistance(double a, double b);
};


#endif //COP4534_P3_MATRIXMANAGER_HPP

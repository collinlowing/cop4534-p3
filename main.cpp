/***************************************************************
  Student Name: Collin Lowing
  File Name: main.cpp
  Project 3

  Runs the program
***************************************************************/

#include <iostream>

int main() {
    int numOfCities;
    int generationSize;
    int numOfGenerations;
    double mutationPercentage;

    std::cout << "How many cities do you want to simulate?" << std::endl;
    std::cin >> numOfCities;

    std::cout << "How many individual tours are in a generation?" << std::endl;
    std::cin >> generationSize;

    std::cout << "How many generations are to run?" << std::endl;
    std::cin >> numOfGenerations;

    std::cout << "What percent of generations will be mutations?" << std::endl;
    std::cin >> mutationPercentage;

    return 0;
}

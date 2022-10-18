/***************************************************************
  Student Name: Collin Lowing
  File Name: main.cpp
  Project 3

  Runs the program
***************************************************************/

#include <iostream>
#include <chrono>
#include "BruteForce.hpp"
#include "Genetic.hpp"

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

    // get bruteforce results
    BruteForce bruteForce(numOfCities);
    auto start = std::chrono::steady_clock::now();
    std::vector<int> bruteForceOptimalPath = bruteForce.performBruteForce();
    auto finish = std::chrono::steady_clock::now();
    double elapsedSeconds =
            std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();

    // print out brute force results
    //PermutationGenerator::printVector(bruteForceOptimalPath);
    std::cout << "finished in " << elapsedSeconds << " seconds" << std::endl;

    return 0;
}

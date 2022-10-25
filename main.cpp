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

    /*std::cout << "starting genetic algorithm\n" << std::endl;

    //get genetic result
    Genetic genetic(numOfCities, generationSize, numOfGenerations, mutationPercentage);
    auto startGenetic = std::chrono::steady_clock::now();
    genetic.performGenetic();
    auto finishGenetic = std::chrono::steady_clock::now();
    double elapsedSecondsGenetic =
            std::chrono::duration_cast<std::chrono::duration<double>>(finishGenetic - startGenetic).count();

    std::cout << "finished in " << elapsedSecondsGenetic << " seconds" << std::endl;*/

    std::cout << "starting brute force algorithm\n" << std::endl;

    // get bruteforce results
    BruteForce bruteForce(numOfCities);
    auto startBruteForce = std::chrono::steady_clock::now();
    std::vector<int> bruteForceOptimalPath = bruteForce.performBruteForce();
    auto finishBruteForce = std::chrono::steady_clock::now();
    double elapsedSecondsBruteForce =
            std::chrono::duration_cast<std::chrono::duration<double>>(finishBruteForce - startBruteForce).count();

    // print out brute force results
    //PermutationGenerator::printVector(bruteForceOptimalPath);
    std::cout << "finished in " << elapsedSecondsBruteForce << " seconds" << std::endl;

    return 0;
}

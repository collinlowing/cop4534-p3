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

double getPercentageOf(double a, double b) {
    return (a / b) * 100;
}

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

    std::cout << "What percent of generations will be mutations? (0.00 to 1.00)" << std::endl;
    std::cin >> mutationPercentage;

    // check for user error
    while(mutationPercentage < 0 || mutationPercentage > 1) {
        std::cout << "Percent must be greater than 0 and less than 1" << std::endl;
        std::cin >> mutationPercentage;
    }


    std::cout << std::endl << "starting genetic algorithm\n" << std::endl;

    //get genetic result
    Genetic genetic(numOfCities, generationSize, numOfGenerations, mutationPercentage);
    auto startGenetic = std::chrono::steady_clock::now();
    double geneticCost = genetic.performGenetic();
    auto finishGenetic = std::chrono::steady_clock::now();
    double elapsedSecondsGenetic =
            std::chrono::duration_cast<std::chrono::duration<double>>(finishGenetic - startGenetic).count();

    std::cout << "finished in " << elapsedSecondsGenetic << " seconds" << std::endl;


    std::cout << std::endl << "starting brute force algorithm\n" << std::endl;

    // get bruteforce results
    BruteForce bruteForce(numOfCities);
    auto startBruteForce = std::chrono::steady_clock::now();
    double bruteForceCost = bruteForce.performBruteForce();
    auto finishBruteForce = std::chrono::steady_clock::now();
    double elapsedSecondsBruteForce =
            std::chrono::duration_cast<std::chrono::duration<double>>(finishBruteForce - startBruteForce).count();

    std::cout << "finished in " << elapsedSecondsBruteForce << " seconds" << std::endl;

    // get percentage of optimal cost
    std::cout << std::endl << "the genetic algorithm performed " << getPercentageOf(geneticCost, bruteForceCost)
            << "% of the optimal cost" << std::endl;

    return 0;
}
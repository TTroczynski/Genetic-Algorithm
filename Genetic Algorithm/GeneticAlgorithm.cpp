#include "GeneticAlgorithm.h"
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm(int populationSize, int generations) : mPopulationSize{ populationSize }, mGenerations{ generations }
{
}

Solution GeneticAlgorithm::run(int numberOfBits, int low, int high)
{
	Solution best(numberOfBits, low, high);

	std::vector<Solution> currentGeneration;

	for (int i = 0; i < mPopulationSize; i++) {
		currentGeneration.push_back(Solution(numberOfBits, low, high));
	}

	std::cout << "First generation:" << std::endl;
	for (Solution s : currentGeneration) {
		std::cout << s.toString();
	}

	for (int i = 0; i < mGenerations; i++) {

		std::vector<Solution> crossedSolutions = tournamentCrossover();
	}


	return best;
}

std::vector<Solution> GeneticAlgorithm::tournamentCrossover(std::vector<Solution> &currentGeneration) {
	std::vector<Solution> newSolution;

	while (newSolution.size() < mGenerations) {

	}
}

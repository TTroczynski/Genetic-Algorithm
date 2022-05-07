#pragma once
#include "Solution.h"

class GeneticAlgorithm {
	int mPopulationSize;
	int mGenerations;

public:

	GeneticAlgorithm(int populationSize, int generations);
	Solution run(int numberOfBits, int low, int high);
	std::vector<Solution> tournamentCrossover(std::vector<Solution>& currentGeneration);
};
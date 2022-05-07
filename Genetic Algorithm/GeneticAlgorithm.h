#pragma once
#include "Solution.h"

class GeneticAlgorithm {
	int mPopulationSize;
	int mGenerations;
	int mTournamentGroupSize;
	int mCrossoverProbability;

public:

	GeneticAlgorithm(int populationSize, int generations, int tournamentGroupSize, double crossoverProbability);
	Solution run(int numberOfBits, int low, int high);
	std::vector<Solution> tournamentCrossover(std::vector<Solution>& currentGeneration);
	Solution tournamentWinner(std::vector<Solution>& currentGeneration);

	
};
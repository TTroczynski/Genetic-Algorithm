#include "GeneticAlgorithm.h"
#include <iostream>
#include <set>
#include "Utility.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, int generations, int tournamentGroupSize, double crossoverProbability)
	: mPopulationSize{ populationSize }, 
	mGenerations{ generations }, 
	mTournamentGroupSize{tournamentGroupSize}
{
}

Solution GeneticAlgorithm::run(int numberOfBits, int low, int high)
{
	Solution best(numberOfBits, low, high, mCrossoverProbability);

	std::vector<Solution> currentGeneration;

	for (int i = 0; i < mPopulationSize; i++) {
		currentGeneration.push_back(Solution(numberOfBits, low, high, mCrossoverProbability));
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

Solution GeneticAlgorithm::tournamentWinner(std::vector<Solution>& currentGeneration) {

	std::vector<Solution> candidates;

	std::set<int> randomNumbers = randomDistinctNumbers(mPopulationSize, mTournamentGroupSize);

	for (int rs : randomNumbers) {
		candidates.push_back(currentGeneration[rs]);
	}

	Solution bestCandidate = candidates[0];

	double maxFitness = candidates[0].fitness();

	for (Solution s : candidates) {
		double fitness = s.fitness();

		if (fitness > maxFitness) {
			maxFitness = fitness;
			bestCandidate = s;
		}
	}

	return bestCandidate;
}

std::vector<Solution> GeneticAlgorithm::tournamentCrossover(std::vector<Solution> &currentGeneration) {
	std::vector<Solution> newSolution;

	while (newSolution.size() < mPopulationSize) {
		
		Solution winner1 = tournamentWinner(currentGeneration);
		Solution winner2 = tournamentWinner(currentGeneration);

		//perform crossover
		std::vector<Solution> children = singlePointCrossover(winner1, winner2);
		
	}
}


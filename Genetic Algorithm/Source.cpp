//Genetic algorithms best suited for optimization problems
//a set of 2 options such as:

//2 cities to visit - A and B
//2 combinations: AB, BA
//3 cities to visit - A, B and C
//6 combinations: ABC, ACB, BAC, BCA, CAB, CBA

//the general principle is that for N cities, therea are N permutations
//so there are N! possibilities

//factorials are the most expensive in terms of time-complexity

//solution: Stochastic algorithms like genetic algorithms.
//solutions based on probabilities
//solutions are determined much faster than N!

//Genetic algorithm based on darwins theory of evolution
//children inherit traits from the mother and father
//children have a chance of gene mutation


//1. Split the problem set into 'chromosomes'
//- Numbers: represent in binary
//7 = 0000 0111
//- Strings: represent as characters
//"hello" = 'h','e','l','l','o'
//- Graphs: represented as nodes
//node combinations ABC, CBA, ...

//2. Use a fitness function to determine the best solutions set (survival of the fittest)

//3. Generate random solutions


//Number of solutions is called 'population size'
//a set of solutions is called a 'generation'

//The first generation of solutions is completely random
//then some solutions are selected for 'cross over' (generate children)
//the selection of solutions to cross over is determined by the fitness function (probability of selection is a parameter set by the programmer)
//Mutation randomely affects some solutions (mutation probability is a parameter set by the programmer)

//Elitism can also be introduced. 
//- retaining a set of the best solutions regardless of the outcome of the fitness function
//to generate children from.

//some implementations of a genetic algorithm only allow survival to following generations if 
//the solution has a better 'fitness' than the current generation.


//---------------------------------------------------
//Crossover probability
//---------------------------------------------------
//after selecting a set of solutions
//we decide with a certain probability if these solutions will crossover or not. (70-100% fitness)
//- if they do not pass this criteria for cross over, they continue to the next generation unchanged (children are clones of parents)

//2 ways of determining crossover: Tournament & Roulette wheel
//can use other methods too

//Tournament Selection
//parameter K - determines the number of solutions to evaluate for fitness
//The fittest wins.

// 1, 6, 9
// 9 wins

//4, 2, 10, 6
//10 wins

//then we determine if the best solutions will cross over


//---------------------------------------
//Roulette Wheel
//---------------------------------------
//solutions are arranged from highest to lowest fitness
//solutions fitness is expressed as a percentage of the whole solution set

//roulette wheel uses chance to select the solution set with the best fitness
//a number is randomely generated from 0-100

//example: if a random number : 27 is generated. and the first solution set constains a fitness of 43. 
//27 falls in the range of 0-43 so solution set 1 is chosen.
//Solution set 2 contains a fitness of 28. It occupies the fitness range of 43 + 28 = 71
//so if a random number 63 is generated, solution set 2 is chosen.

//SO, larger fitness = larger probability of selection


//----------------------------------------
//cross over
//----------------------------------------
//different methods for selecting sets for cross over
//common to select a point at random 

//example for numbers:

//A = 11000101
//B = 10011011

//randomly select a cross over point

//A = 110|00101
//B = 100|11011

//swap the set of LSBs with eachother, to generate children

//child of A: 110|11011
//child of B: 100|00101

//---------------------
//Multipoint crossover 
//---------------------

//A = 110|00|101
//B = 100|11|011

//child of A: 11011101
//child of B: 10000011

//---------------------
//Uniform crossover
//---------------------

//each bit is assessed independently. Some cross over function is used to determine
//the cross over of each bit on a bit-by-bit level AT RANDOM.
//each bit is determined to cross over with a 50-50 chance.


//after cross over is complete, Mutation begins
//we select a bit, using a probability calculation, to flip

//if the solutions are string, we choose a random character to exchange one with

//XDFSFG -> XAFSFG

//if the solutions are node ccombinations, we swap two nodes in the solution.
//the solutions in this case represent the order in which to visit the nodes

//{A, B, C, D, E} -> {A, C, B, D, E}
//**cant change the name of the city. The set represents existing 'cities' to visit in a particular order


//Parameters:

//Mutation rate - too high creates chaos and meaningless results
//				- too low will cause the algorithm to continuously generate solutions at a local max/min
//				(gets stuck at what it beleives is the best solution - not enough randomness)

//Population size	- too high causes slow execution
//					- too low causes poor results. Or best results it can generate, but not a good enough result for us



//Genetic algorithm needs:
//1. random initial population
//2. a fitness function
//3. crossover function
//4. mutation function

#include "GeneticAlgorithm.h"
#include <time.h>



int main(void) {
	srand(time(NULL));

	int mPopulationSize = 100;
	int mGenerations = 20;
	int mBits = 8;
	int low = 0;
	int high = 4;
	int tournamentGroupSize = 3;
	double crossoverProbability = 0.7;
	
	GeneticAlgorithm ga(mPopulationSize, mGenerations, tournamentGroupSize, crossoverProbability);
	Solution bestSolution = ga.run(mBits, low, high);


	return 0;
}
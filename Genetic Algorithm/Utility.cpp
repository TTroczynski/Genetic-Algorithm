#include "Utility.h"
#include <cstdlib>
#include <stdexcept>

double randomDouble() {
	return (double)(rand() % 1000) / 1000;
}

//given a probability from 0-1 (0% to 100%)
//generate a random number between 0-1. If the generated number is within the range of the 
//probability then return true
//if the generated number is outside of the range of the probability, return false

//example, passed in probability: 70% = 0.7
//generate number 0.5
//returns true
//generate number 0.8
//returns false
bool randomProbability(double probability) {
	if (probability < 0 || probability > 1) {
		throw std::runtime_error("Probability should be between 0 and 1");
	}

	double r = randomDouble();

	if (r < probability) {
		return true;
	}
	else {
		return false;
	}

}

//This function converts binary values to floating point values within a range of digits we need
// if were working with 8 bit values, we need all values caluated to within 8 bits.
//Since this algorithm solves continuous problems, the use of floating point values is neccessary
//the use of floatin point values introduces the problem of large decimal values. 
//So the values need to be 'bounded' to range of digits

//Precision: (high-low)/((2^n) - 1)
//where: high - low is the desired range
//(2^n) - 1 is the range of values represented by N bits. 8 bits = 255 base 10

//example: precision = 0.156
//bit value in base 10 = 178
//178*0.156 = 27.768
//27.768 + 10 (lower bound) = 37.768

double precision(int low, int high, int numberOfBits) {
	return (double)(high - low) / (double)(pow(2, numberOfBits) - 1);
}

//generates a set of a specified size with random numbers
std::set<int> randomDistinctNumbers(int upperLimit, int howManyNumbers) {
	std::set<int> numbers;

	while (numbers.size() < howManyNumbers) {
		numbers.insert(rand() % upperLimit);
	}
	return numbers;
}
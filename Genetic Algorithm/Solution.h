#pragma once

#include <vector>
#include <string>

//most efficient if we represent 8 bits with a single char value but for simplicity, ill use ints
class Solution
{
	int mNumberOfBits;
	int mLow;
	int mHigh;
	std::vector<int> bits;

	double bitsToDouble();

public:

	Solution(int numberOfBits, int low, int high);
	Solution(int numberOfBits, int low, int high, std::vector<int> bits);
	std::string toString();
	double fitness();
	std::vector<Solution> singlePointCrossover(Solution s1, double crossoverProbability);

};


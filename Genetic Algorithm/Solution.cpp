#include "Solution.h"
#include <sstream>
#include "Utility.h"
#include <iostream>

Solution::Solution(int numberOfBits, int low, int high) : 
	mNumberOfBits{ numberOfBits }, 
	mLow{ low }, 
	mHigh{ high } {

	//reserves 8 indices to avoid reallocating when we exceed 1 elements because a vectors 
	//size is initially 1 element wide.
	bits.reserve(numberOfBits);

	for (int i = 0; i < numberOfBits; i++) {
		bits.push_back(rand() % 2); // values 0 - 1 are randomely generated
	}
}

Solution::Solution(int numberOfBits, int low, int high, std::vector<int> inBits) :
	mNumberOfBits{ numberOfBits },
	mLow{ low },
	mHigh{ high },
	bits{inBits}
{

}

std::string Solution::toString() {

	std::ostringstream stream;

	stream << "[";
	for (int i = 0; i < mNumberOfBits; i++) {
		stream << bits.at(i) << " ";
	}

	stream << "] double = "<< bitsToDouble() << " fitness " << fitness() << std::endl;

	return stream.str();
}

double Solution::fitness()
{
	double floatValue = bitsToDouble();
	return floatValue + 2 * sin(floatValue);
}

//converts to floating point value
double Solution::bitsToDouble(){
	double mPrecision = precision(mLow, mHigh, mNumberOfBits);
	int dec = 0;

	//converts bin to dec
	for (int i = 0; i < mNumberOfBits; i++) {
		dec = dec + pow(2, i) * bits[i];
	}
	return dec * mPrecision + mLow;

}

std::vector<Solution> Solution::singlePointCrossover(Solution other, double crossoverProbability) {

	bool cross = randomProbability(crossoverProbability);

	std::cout << " Cross ? " << cross << std::endl;

	if (cross) {

		int crossPoint = rand() % mNumberOfBits;

		std::vector<int> bits1;
		std::vector<int> bits2;

		std::copy(this->bits.begin(), this->bits.begin() + crossPoint, std::back_inserter(bits1));
		std::copy(other.bits.begin() + crossPoint, other.bits.end(), std::back_inserter(bits1));

		std::copy(this->bits.begin(), this->bits.begin() + crossPoint, std::back_inserter(bits2));
		std::copy(other.bits.begin() + crossPoint, other.bits.end(), std::back_inserter(bits2));

		Solution child1{ mNumberOfBits, mLow, mHigh, bits1 };
		Solution child2{ mNumberOfBits, mLow, mHigh, bits2 };
		


		return { child1, child2 };
	}
	else {
		return { *this, other };
	}


}
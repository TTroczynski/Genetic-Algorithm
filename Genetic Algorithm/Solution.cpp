#include "Solution.h"
#include <sstream>
#include "Utility.h"

Solution::Solution(int numberOfBits, int low, int high, double crossoverProbability) : 
	mNumberOfBits{ numberOfBits }, 
	mLow{ low }, 
	mHigh{ high }, 
	mCrossoverProbability{ crossoverProbability } {

	//reserves 8 indices to avoid reallocating when we exceed 1 elements because a vectors 
	//size is initially 1 element wide.
	bits.reserve(numberOfBits);

	for (int i = 0; i < numberOfBits; i++) {
		bits.push_back(rand() % 2); // values 0 - 1 are randomely generated
	}
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

	if (cross) {

		int crossPoint = rand() % mNumberOfBits;

		std::vector<Solution> children;

		std::vector<int> bits1;
		std::vector<int> bits2;

		std::copy(this->mNumberOfBits.begin(), this->mNumberOfBits.begin() + crossPoint, std::back_inserter(bits1));
		std::copy(other.bits.begin() + crossPoint, std::back_inserter(bits1));



		children;
	}
	else {
		return { *this, other };
	}


}
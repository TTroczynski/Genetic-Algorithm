#include "Solution.h"
#include <sstream>
#include "Utility.h"

Solution::Solution(int numberOfBits, int low, int high) : mNumberOfBits{ numberOfBits }, mLow{ low }, mHigh{ high } {

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

	stream << "] double = "<< bitsToDouble() << std::endl;
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
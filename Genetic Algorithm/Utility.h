#pragma once
#include <set>
//header containing function that will return a set of random numbers between a specified high and low limit

double randomDouble();

bool randomProbability(double probability);

double precision(int low, int high, int numberOfBits);

std::set<int> randomDistinctNumbers(int upperLimit, int howManyNumbers);

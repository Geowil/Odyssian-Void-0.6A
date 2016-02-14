#ifndef RANDOM_H
#define RANDOM_H

#include <random>

std::random_device rd;
std::mt19937 gen(rd());

int getIRange(int low, int high)
{
	return std::uniform_int_distribution<>{low, high}(gen);
}

float getFRange(float low, float high)
{
	return std::uniform_real_distribution<float> {low, high}(gen);
}

#endif

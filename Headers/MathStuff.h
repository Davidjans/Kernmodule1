#pragma once
#include <cmath>
class MathStuff
{
public:
	float static Power(float base, float powerOf);
	float static Square(float numberToSquare);
	float static SquareRoot(float numberToSquareRoot, float errorMargin = 0);
};
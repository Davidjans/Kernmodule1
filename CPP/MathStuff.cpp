#include "MathStuff.h"
#include <iostream>
float MathStuff::Power(float base, float powerOf)
{
	if (powerOf <= 1)
		std::cout << "Trying to do a invalid power calculation";
	float currentResult = base;

	for (size_t i = 0; i < powerOf - 1; i++)
	{
		currentResult = currentResult * base;
	}
	return currentResult;
}

float MathStuff::Square(float numberToSquare)
{
	if (numberToSquare == 0) {
		return 0;
	}
	return numberToSquare * numberToSquare;
}

float MathStuff::SquareRoot(float numberToSquareRoot, float errorMargin)
{
	if (numberToSquareRoot <= 0)
	{
		return 0;
	}
	float a = 1;
	float b = numberToSquareRoot;
	while (abs(a - b) > errorMargin) {
		a = (a + b) / 2;
		b = numberToSquareRoot / a;
	}
	return a;
}
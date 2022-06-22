#include "BaseStuff.h"

#include <random>

#include "MathStuff.h"
BaseStuff* BaseStuff::m_ManagerInstance = new BaseStuff();
float BaseStuff::CalculateDistance(float firstX, float firstY, float secondX, float secondY)
{
	float distance;
	float xSquared = MathStuff::Square(secondX - firstX);
	float ySquared = MathStuff::Square(secondY - firstY);
	//distance = sqrt( MathStuff::Square(firstX - secondX) * MathStuff::Square (firstY-secondY));
	distance = MathStuff::SquareRoot(xSquared + ySquared, 0.5f);

	return distance;
}

std::vector<std::string> BaseStuff::SplitString(std::string textToSplit, char splitter )
{
	std::vector<std::string> wordList = std::vector<std::string>();
	std::string word = "";
	for (auto x : textToSplit)
	{
		if (x == splitter)
		{
			wordList.push_back(word);
			word = "";
		}
		else {
			word = word + x;
		}
	}
	if (word.size() > 0)
		wordList.push_back(word);
	return wordList;
}

int BaseStuff::GetIndexOf(std::vector<Enums::Layer> listToCheck, Enums::Layer thingToFind)
{
	for (size_t i = 0; i < listToCheck.size(); i++)
	{
		if (listToCheck.at(i) == thingToFind)
		{
			return i;
		}
	}
	return -1;
}



void BaseStuff::SetDeltaTime()
{
	m_DeltaTime = m_DeltaClock.restart();
}

sf::Time BaseStuff::GetDeltaTime()
{
	return m_DeltaTime;
}

BaseStuff* BaseStuff::GetInstance()
{
	if (m_ManagerInstance == nullptr)
		m_ManagerInstance = new BaseStuff();
	return m_ManagerInstance;
}

float BaseStuff::GetRandomNumber(float x, float y)
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_real_distribution<float> uniform_dist(x, y);
	float mean = uniform_dist(e1);
	return mean;
}
int BaseStuff::GetRandomNumber(int x, int y)
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(x, y);
	int mean = uniform_dist(e1);
	return mean;
}
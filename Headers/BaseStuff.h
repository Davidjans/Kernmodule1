#pragma once
#include <iostream>
#include <SFML/System/Clock.hpp>
class GameObject;
#include "Enums.h"
#include <vector>
//template <class T>
class BaseStuff
{
public:
	static float CalculateDistance(float firstX, float firstY, float secondX, float secondY);
	static std::vector<std::string> SplitString(std::string textToSplit, char splitter);
	// I really want generics so i can make this work :(
	static int GetIndexOf(std::vector<Enums::Layer> listToCheck, Enums::Layer thingToFind);

	static BaseStuff* GetInstance();

	static float GetRandomNumber(float x,float y);
	static int GetRandomNumber(int x, int y);

	void SetDeltaTime();
	sf::Time GetDeltaTime();
	
private:
	static BaseStuff* m_ManagerInstance;
	sf::Time m_DeltaTime;
	sf::Clock m_DeltaClock;
};

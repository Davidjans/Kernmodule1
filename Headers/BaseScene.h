#pragma once
#include <iostream>
class GameManager;
class BaseScene
{
public:
	GameManager* m_GameManager;

	virtual void Update();
	virtual void LoadScene();
	virtual void UnloadScene();

	BaseScene();
	~BaseScene();
};

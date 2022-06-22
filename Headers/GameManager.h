#pragma once
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "ColissionChecker.h"
#include <SFML/Graphics.hpp>
#include "ScoreManager.h"
#include "BaseScene.h"
class GameManager
{
private:

	GameManager();
public:
	CollisionChecker* m_CollisionChecker;
	std::vector<GameObject*> m_GameObjects;
	std::vector<sf::Drawable*> m_ThingsToDraw;
	BaseScene* m_CurrentScene;
	sf::Vector2i m_MousePos;
	sf::RenderWindow* m_RenderWindow;
	int m_FramesSinceUpdateStop = 0;
	bool m_StopUpdate = false;
	void LoadScene(BaseScene* sceneToLoad);
	void Update();

	~GameManager();
	static GameManager* GetInstance();
	static GameManager* m_ManagerInstance;
};

#include "GameManager.h"
#include "BaseScene.h"
#include <iostream>

#include "BaseStuff.h"
GameManager* GameManager::m_ManagerInstance = new GameManager();

GameManager* GameManager::GetInstance()
{
	if (m_ManagerInstance == nullptr)
		m_ManagerInstance = new GameManager();
	return m_ManagerInstance;
}

GameManager::GameManager()
{
	m_CollisionChecker = CollisionChecker::GetInstance();
	m_FramesSinceUpdateStop = 0;
	m_StopUpdate = false;
}

GameManager::~GameManager()
{
}

void GameManager::LoadScene(BaseScene* sceneToLoad)
{
	if (m_CurrentScene != nullptr) {
		m_CurrentScene->UnloadScene();
		for (size_t i = 0; i < m_GameObjects.size(); i++)
		{
			m_GameObjects.at(i)->m_Delete = true;
			delete m_GameObjects.at(i);
		}
		m_GameObjects.clear();
		delete m_CurrentScene;
	}
	m_CurrentScene = sceneToLoad;
	m_CurrentScene->LoadScene();

	// really wanna find another way to do this;
	m_FramesSinceUpdateStop = 0;
	m_StopUpdate = true;
}

void GameManager::Update()
{
	m_MousePos = sf::Mouse().getPosition(*m_RenderWindow);
	m_CurrentScene->Update();
	for (size_t i = 0; i < m_GameObjects.size(); i++)
	{
		if (m_StopUpdate) {
			break;
		}
		m_GameObjects.at(i)->Update();
	}
	for (size_t i = 0; i < m_GameObjects.size(); i++)
	{
		if (m_GameObjects.at(i)->m_Delete)
		{
			delete m_GameObjects.at(i);
			m_GameObjects.erase(m_GameObjects.begin() + i);
			continue;
		}
	}
	if (!m_StopUpdate)
		m_CollisionChecker->CheckWhatCollided();
	m_StopUpdate = false;
	
	BaseStuff::GetInstance()->SetDeltaTime();
}
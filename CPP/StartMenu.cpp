#include "StartMenu.h"
#include <direct.h>
#include <iostream>
#include "StartButton.h"
#include "GameManager.h"

void StartMenu::LoadScene()
{
	GameObject* object = new GameObject();

	
	std::string normal = "NormalStartButtonTexture.png";
	std::string down = "DownStartButtonTexture.png";
	object->AddComponent(new StartButton(object, normal, down, std::string(""), sf::Vector2f(20, 20)));

	object->m_Position.x = GameManager::GetInstance()->m_RenderWindow->getSize().x / 2;
	object->m_Position.y = GameManager::GetInstance()->m_RenderWindow->getSize().y / 2;
}

void StartMenu::UnloadScene()
{
}
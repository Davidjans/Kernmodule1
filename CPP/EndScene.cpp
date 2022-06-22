#include "EndScene.h"

#include <SFML/Graphics/Texture.hpp>

#include "GameManager.h"
#include "GameObject.h"
#include "StartButton.h"

void EndScene::LoadScene()
{
	GameObject* object = new GameObject();


	std::string normal = "NormalStartButtonTexture.png";
	std::string down = "DownStartButtonTexture.png";
	object->AddComponent(new StartButton(object, normal, down, std::string(""), sf::Vector2f(20, 20)));

	object->m_Position.x = GameManager::GetInstance()->m_RenderWindow->getSize().x / 2;
	object->m_Position.y = GameManager::GetInstance()->m_RenderWindow->getSize().y / 2;

	m_Font->loadFromFile("arial.ttf");
	m_ScoreText = new sf::Text();
	m_ScoreText->setCharacterSize(24);
	m_ScoreText->setFillColor(sf::Color::White);
	m_ScoreText->setPosition(GameManager::GetInstance()->m_RenderWindow->getSize().x /2 - 50, GameManager::GetInstance()->m_RenderWindow->getSize().y / 3);
	m_ScoreText->setFont(*m_Font);
	m_ScoreText->setString("Final Score: "+ std::to_string(ScoreManager::GetInstance()->GetScore()));
	GameManager::GetInstance()->m_ThingsToDraw.push_back(m_ScoreText);
}

void EndScene::UnloadScene()
{
	for (size_t i = 0; i < GameManager::GetInstance()->m_ThingsToDraw.size(); i++)
	{
		if (GameManager::GetInstance()->m_ThingsToDraw.at(i) == m_ScoreText)
			GameManager::GetInstance()->m_ThingsToDraw.erase
			(GameManager::GetInstance()->m_ThingsToDraw.begin() + i);
	}
	delete m_ScoreText;
	delete m_Font;
}
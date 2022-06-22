#include "ScoreManager.h"
#include "GameManager.h"
ScoreManager* ScoreManager::m_ManagerInstance = new ScoreManager();

ScoreManager* ScoreManager::GetInstance()
{
	if (m_ManagerInstance == nullptr)
		m_ManagerInstance = new ScoreManager();
	return m_ManagerInstance;
}

void ScoreManager::SetScore(int ammountToSet)
{
	m_Score = ammountToSet;
	SetScoreText();
}

int ScoreManager::GetScore()
{
	return m_Score;
}

void ScoreManager::AddScore(int ammountToAdd)
{
	m_Score += ammountToAdd;
	SetScoreText();
}

void ScoreManager::EnableScoreDisplay()
{
	bool contains = false;
	for (size_t i = 0; i < GameManager::GetInstance()->m_ThingsToDraw.size(); i++)
	{
		if (GameManager::GetInstance()->m_ThingsToDraw.at(i) == m_ScoreText)
			contains = true;
	}
	if (!contains)
		GameManager::GetInstance()->m_ThingsToDraw.push_back(m_ScoreText);
}

void ScoreManager::DisableScoreDisplay()
{
	for (size_t i = 0; i < GameManager::GetInstance()->m_ThingsToDraw.size(); i++)
	{
		if (GameManager::GetInstance()->m_ThingsToDraw.at(i) == m_ScoreText)
			GameManager::GetInstance()->m_ThingsToDraw.erase
			(GameManager::GetInstance()->m_ThingsToDraw.begin() + i);
	}
}

void ScoreManager::SetScoreText()
{
	
	m_ScoreText->setString("Score: " + std::to_string(m_Score));
}

ScoreManager::ScoreManager()
{
	m_Font->loadFromFile("arial.ttf");
	m_ScoreText = new sf::Text();
	m_ScoreText->setCharacterSize(24);
	m_ScoreText->setFillColor(sf::Color::White);
	m_ScoreText->setPosition(100, 100);
	m_ScoreText->setFont(*m_Font);
	SetScoreText();
}

ScoreManager::~ScoreManager()
{
}
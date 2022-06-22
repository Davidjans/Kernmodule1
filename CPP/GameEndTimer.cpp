#include "GameEndTimer.h"

#include "BaseStuff.h"
#include "EndScene.h"
#include "GameManager.h"
#include "StartMenu.h"

void GameEndTimer::Update()
{
	Component::Update();
	m_CurrentTimer -= BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
	SetTimerText();
	if (m_CurrentTimer <= 0)
		GameManager::GetInstance()->LoadScene(new EndScene());
}

GameEndTimer::GameEndTimer(GameObject* parentObject): Component(parentObject)
{
	m_CurrentTimer = m_TimerStartAmmount;
	m_Font->loadFromFile("arial.ttf");
	
	m_TimerText = new sf::Text();
	m_TimerText->setCharacterSize(24);
	m_TimerText->setFillColor(sf::Color::White);
	m_TimerText->setPosition(200, 100);
	m_TimerText->setFont(*m_Font);
	GameManager::GetInstance()->m_ThingsToDraw.push_back(m_TimerText);
	SetTimerText();
}

GameEndTimer::~GameEndTimer()
{
	GameManager::GetInstance()->m_ThingsToDraw.erase(std::remove(GameManager::GetInstance()->m_ThingsToDraw.begin(), GameManager::GetInstance()->m_ThingsToDraw.end(), m_TimerText), GameManager::GetInstance()->m_ThingsToDraw.end());
	delete m_TimerText;
	delete m_Font;
}

void GameEndTimer::SetTimerText()
{
	m_TimerText->setString("Time:" + std::to_string((int)m_CurrentTimer));
}

#include "Button.h"
#include <iostream>
#include "GameManager.h"
#include "BaseStuff.h"
Button::Button(GameObject* parentObject, std::string normal, std::string clicked, std::string words, sf::Vector2f location) : Component(parentObject) {
	m_NormalTexture = sf::Texture();
	m_DownTexture = sf::Texture();

	m_NormalTexture.loadFromFile(normal);
	m_DownTexture.loadFromFile(clicked);

	m_Normal.setTexture(m_NormalTexture);
	m_ButtonDown.setTexture(m_DownTexture);
	m_CurrentSpr = &this->m_Normal;
	m_Current = false;
	m_Normal.setPosition(location);
	m_ButtonDown.setPosition(location);
	m_ButtonText = new sf::Text();
	m_ButtonText->setString(words);
	m_ButtonText->setPosition(location.x + 3, location.y + 3);
	m_ButtonText->setCharacterSize(14);
	m_Font->loadFromFile("arial.ttf");
	m_ButtonText->setFont(*m_Font);

	m_ParentObject->m_GameManager->m_ThingsToDraw.push_back(m_CurrentSpr);
	m_ParentObject->m_GameManager->m_ThingsToDraw.push_back(m_ButtonText);
	//m_ParentObject->m_GameManager->m_ThingsToDraw->push_back(m_ButtonText);
}
bool Button::CheckOver(sf::Vector2i mousePos) {
	//std::cout << mousePos.x << std::endl << mousePos.y << std::endl;
	if (m_CurrentSpr/*m_TempShape*/->getGlobalBounds().contains(sf::Vector2f(
		mousePos.x
		, mousePos.y)))
	{
		return true;
	}
	return false;
}
void Button::setState(bool which) {
	m_Current = which;
	if (m_Current) {
		m_CurrentSpr = &m_ButtonDown;
		return;
	}
	m_CurrentSpr = &m_Normal;
}
void Button::setText(std::string words) {
	m_ButtonText->setString(words);
}
bool Button::getVar() {
	return m_Current;
}
sf::Sprite* Button::getSprite() {
	return m_CurrentSpr;
}

sf::String* Button::getText() {
	return new sf::String(m_ButtonText->getString());
}

void Button::Update()
{
	//m_CurrentSpr->setPosition(sf::Vector2f(*m_ParentObject->m_XPos, *m_ParentObject->m_YPos));
	m_ButtonText->setPosition(sf::Vector2f(m_ParentObject->m_Position.x + 3, m_ParentObject->m_Position.y + 3));
	m_CurrentSpr->setPosition(sf::Vector2f(m_ParentObject->m_Position.x - 
		(m_CurrentSpr->getLocalBounds().getSize().x / 2), 
		m_ParentObject->m_Position.y - m_CurrentSpr->getLocalBounds().getSize().y / 2));
	if (*m_ButtonState == up)
	{
		*m_ButtonState = normal;
	}
	bool buttonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	if (CheckOver(m_ParentObject->m_GameManager->m_MousePos))
	{
		if (*m_ButtonState == normal && buttonPressed)
		{
			*m_ButtonState = down;
			m_CurrentSpr = &m_ButtonDown;
		}
		else if (*m_ButtonState == down && !buttonPressed) {
			*m_ButtonState = up;
			m_CurrentSpr = &m_Normal;
			OnButtonClick();
			return;
		}
	}
	else if (*m_ButtonState == down && !buttonPressed)
	{
		*m_ButtonState = normal;
		m_CurrentSpr = &m_Normal;
	}
}

void Button::OnButtonClick()
{
}

Button::~Button()
{
	GameManager::GetInstance()->m_ThingsToDraw.erase(std::remove(GameManager::GetInstance()->m_ThingsToDraw.begin(), GameManager::GetInstance()->m_ThingsToDraw.end(), m_ButtonText), GameManager::GetInstance()->m_ThingsToDraw.end());
	GameManager::GetInstance()->m_ThingsToDraw.erase(std::remove(GameManager::GetInstance()->m_ThingsToDraw.begin(), GameManager::GetInstance()->m_ThingsToDraw.end(), m_CurrentSpr), GameManager::GetInstance()->m_ThingsToDraw.end());
	
	delete m_ButtonText;
	delete m_ButtonState;
	// not allowed to delete text too lazy to figure it out now so i will later.
	//delete m_ButtonText;
	delete m_Font;
}
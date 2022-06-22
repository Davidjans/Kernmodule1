#include "SpriteRender.h"

#include "Button.h"
#include "GameObject.h"
#include "GameManager.h"
void SpriteRender::Update()
{
	m_Drawable->setPosition(sf::Vector2f(m_ParentObject->m_Position.x, m_ParentObject->m_Position.y));
}

SpriteRender::SpriteRender(GameObject* parentObject, std::string sprite) : Component(parentObject)
{
	m_Texture = sf::Texture();
	
	m_Texture.loadFromFile(sprite);
	m_Drawable = new sf::Sprite();
	m_Drawable->setTexture(m_Texture);
	m_Drawable->setScale(0.3f, 0.3f);
	Vector2 newOrigin = Vector2(0,0);
	newOrigin.x += m_Drawable->getLocalBounds().getSize().x / 2;
	newOrigin.y += m_Drawable->getLocalBounds().getSize().y / 2;
	m_Drawable->setOrigin(newOrigin.x, newOrigin.y);
	GameManager::GetInstance()->m_ThingsToDraw.push_back(m_Drawable);
}

SpriteRender::~SpriteRender()
{
	GameManager::GetInstance()->m_ThingsToDraw.erase(std::remove(GameManager::GetInstance()->m_ThingsToDraw.begin(), GameManager::GetInstance()->m_ThingsToDraw.end(), m_Drawable), GameManager::GetInstance()->m_ThingsToDraw.end());
	delete m_Drawable;
}

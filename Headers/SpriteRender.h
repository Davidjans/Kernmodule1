#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

#include "Vector2.h"

class SpriteRender :
	public Component
{
public:
	void Update() override;
	sf::Sprite* m_Drawable;
	Vector2 m_Offset = Vector2(0,0);
	SpriteRender(GameObject* parentObject, std::string spriteTexture);
	~SpriteRender() override;
private:
	sf::Texture m_Texture;
};

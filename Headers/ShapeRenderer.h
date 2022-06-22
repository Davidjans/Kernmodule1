#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class ShapeRenderer :
	public Component
{
public:
	void Update() override;
	sf::Shape* m_Drawable;
	ShapeRenderer(GameObject* parentObject);
	~ShapeRenderer() override;
};

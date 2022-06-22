#pragma once
#include <SFML/Graphics/Font.hpp>

#include "BaseScene.h"
class EndScene :
    public BaseScene
{
public:
	void LoadScene() override;
	void UnloadScene() override;
	sf::Text* m_ScoreText;

	sf::Font* m_Font = new sf::Font();
};


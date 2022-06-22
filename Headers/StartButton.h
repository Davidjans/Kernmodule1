#pragma once
#include "Button.h"
class StartButton :
	public Button
{
public:
	StartButton(GameObject* parentObject, std::string normal, std::string clicked, std::string, sf::Vector2f location);
	void OnButtonClick() override;
};

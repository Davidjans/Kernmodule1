#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
//#include <SFML/Graphics/Sprite.hpp>
// found this code on the interwebs
class Button :
	public Component {
public:
	enum ButtonStates {
		normal,
		down,
		up
	};
	Button(GameObject* parentObject, std::string normal, std::string clicked, std::string buttonText, sf::Vector2f location);
	bool CheckOver(sf::Vector2i);
	void setState(bool);
	void setText(std::string);
	bool getVar();
	sf::Sprite* getSprite();
	sf::String* getText();
	void Update() override;
	ButtonStates* m_ButtonState = new ButtonStates(normal);
	virtual void OnButtonClick();
	~Button();
private:
	sf::Font* m_Font = new sf::Font();
	sf::Texture m_NormalTexture;
	sf::Texture m_DownTexture;
	sf::Sprite m_Normal;
	sf::Sprite m_ButtonDown;
	sf::Sprite* m_CurrentSpr;
	sf::Text* m_ButtonText;
	bool m_Current;
};

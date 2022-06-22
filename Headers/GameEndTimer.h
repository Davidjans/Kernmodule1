#pragma once
#include <SFML/Graphics.hpp>

#include "Component.h"
class GameEndTimer :
    public Component
{
public:
    int m_TimerStartAmmount = 120;
    float m_CurrentTimer;
    void Update() override;
    GameEndTimer(GameObject* parentObject);
    ~GameEndTimer() override;
private:
    
    sf::Text* m_TimerText;
    void SetTimerText();
    sf::Font* m_Font = new sf::Font();
};
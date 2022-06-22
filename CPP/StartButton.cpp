#include "StartButton.h"
#include "GameObject.h"
#include "GameManager.h"
#include "GameScene.h"
StartButton::StartButton(GameObject* parentObject, std::string normal, std::string clicked, std::string words, sf::Vector2f location) : Button(parentObject, normal, clicked, words, location)
{
}
void StartButton::OnButtonClick()
{
	GameManager::GetInstance()->LoadScene(new GameScene());
}
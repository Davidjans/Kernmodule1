#include "Player.h"
#include "GameManager.h"
#include "CircleCollider.h"
#include "ShapeRenderer.h"
#include "Enums.h"
#include "PlayerMovement.h"
#include "SpriteRender.h"

Player::Player()
{
	AddComponent(new RigidBody(this));
	AddComponent(new CircleCollider(this, 40));
	AddComponent(new SpriteRender(this, "WarriorToken.png"));
	AddComponent(new PlayerMovement(this, 10, 0));
	m_ObjectName = "Player";
	m_ObjectLayer = Enums::Player;
	m_Position.x = GameManager::GetInstance()->m_RenderWindow->getSize().x / 2;
	m_Position.y = GameManager::GetInstance()->m_RenderWindow->getSize().y - 100;
}

#include "Enemy.h"
#include "GameManager.h"
#include "CircleCollider.h"
#include "ShapeRenderer.h"
#include "Enums.h"
#include "MoveGameObject.h"
#include "EnemyFunctionality.h"
#include <random>

#include "BaseStuff.h"
#include "RigidBody.h"
#include "SpriteRender.h"

Enemy::Enemy() : GameObject()
{
	AddComponent(new RigidBody(this));
	AddComponent(new CircleCollider(this, 40));
	//AddComponent(new MoveGameObject(this, 0, 0.1f));
	AddComponent(new SpriteRender(this,"GoblinToken.png"));
	AddComponent(new EnemyFunctionality(this));
	m_ObjectName = "Enemy";
	m_ObjectLayer = Enums::Enemy;
	dynamic_cast<SpriteRender*>(GetComponent("SpriteRender"))->m_Offset.x = 40;
	dynamic_cast<SpriteRender*>(GetComponent("SpriteRender"))->m_Offset.y = 40;
	m_Position.x = BaseStuff::GetRandomNumber(40, GameManager::GetInstance()->m_RenderWindow->getSize().x - 10);
	m_Position.y = 10;
}

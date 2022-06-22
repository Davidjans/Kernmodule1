#include "EnemyManager.h"

#include <random>

#include "BaseStuff.h"
#include "Enemy.h"
#include "GameManager.h"
EnemyManager* EnemyManager::m_ManagerInstance = new EnemyManager();

EnemyManager* EnemyManager::GetInstance()
{
	if (m_ManagerInstance == nullptr)
		m_ManagerInstance = new EnemyManager();
	return m_ManagerInstance;
}

void EnemyManager::Update()
{
	NewEnemySpawningStuff();
}

void EnemyManager::NewEnemySpawningStuff()
{
	m_SecondsLeft -= BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
	if (m_SecondsLeft <= 0)
	{
		SpawnEnemy();
		SetNewNumber();
	}
}

void EnemyManager::SpawnEnemy()
{
	Enemy* enemy = new Enemy();
	m_Enemies.push_back(enemy);
}

void EnemyManager::SetNewNumber()
{
	m_SecondsLeft = BaseStuff::GetRandomNumber(m_SpawnEnemySeconds.x, m_SpawnEnemySeconds.y);
	
}

EnemyManager::EnemyManager()
{
	SetNewNumber();
}



EnemyManager::~EnemyManager()
{

}
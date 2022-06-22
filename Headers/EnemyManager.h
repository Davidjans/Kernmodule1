#pragma once
#include "Enemy.h"
#include  "Vector2.h"
class EnemyManager
{
public:
	static EnemyManager* GetInstance();
	void NewEnemySpawningStuff();
	static EnemyManager* m_ManagerInstance;
	void SpawnEnemy();
	EnemyManager();
	void SetNewNumber();
	~EnemyManager();
	std::vector<Enemy*> m_Enemies;
	void Update();
private:
	Vector2 m_SpawnEnemySeconds = Vector2(2, 4);
	float m_SecondsLeft = 0;
};


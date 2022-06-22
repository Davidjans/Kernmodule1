#pragma once
#include "Component.h"
#include "RigidBody.h"

class EnemyFunctionality
	:public Component
{
public:
	int m_ScoreWorth = 1;
	EnemyFunctionality(GameObject* parentObject);
	RigidBody* m_RigidBody;
	float m_SideMoveTimer = 1;
	float m_CurrentSideMoveTimer = 0;
	float m_SideMoveForce = 10;
	void Update() override;
	void SideMoveStuff();
	void OnCollisionEnter(Collider* col) override;
	void CheckPastDeathZone();
};

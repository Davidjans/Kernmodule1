#include "EnemyFunctionality.h"

#include "BaseStuff.h"
#include "GameManager.h"
#include "ScoreManager.h"
EnemyFunctionality::EnemyFunctionality(GameObject* parentObject) : Component(parentObject)
{
	m_RigidBody = dynamic_cast<RigidBody*>(parentObject->GetComponent("RigidBody"));
	m_RigidBody->m_Acceleration.y = 0.02f;
	m_CurrentSideMoveTimer = m_SideMoveTimer;
}

void EnemyFunctionality::Update()
{
	Component::Update();
	CheckPastDeathZone();
	SideMoveStuff();
}

void EnemyFunctionality::SideMoveStuff()
{
	m_CurrentSideMoveTimer -= BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
	if(m_CurrentSideMoveTimer <= 0)
	{
		m_CurrentSideMoveTimer = m_SideMoveTimer;
		int maxNumber = 3;
		int minNumber = 1;

		int random = BaseStuff::GetRandomNumber(minNumber, maxNumber);
		if(random == maxNumber)
		{
			random = BaseStuff::GetRandomNumber(1, 2);
			if(random == 1)
				m_RigidBody->AddForce(-m_SideMoveForce, 0);
			else
				m_RigidBody->AddForce(m_SideMoveForce, 0);
		}
	}
}

void EnemyFunctionality::OnCollisionEnter(Collider* col)
{
	ScoreManager::GetInstance()->AddScore(m_ScoreWorth);
	m_ParentObject->m_Delete = true;
}

void EnemyFunctionality::CheckPastDeathZone()
{
	if (m_ParentObject->m_Position.y > GameManager::GetInstance()->m_RenderWindow->getSize().y)
	{
		m_ParentObject->m_Delete = true;
		ScoreManager::GetInstance()->AddScore(-m_ScoreWorth);
	}
}

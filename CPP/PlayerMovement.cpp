#include "PlayerMovement.h"
#include "GameObject.h"
#include <Windows.h>
void PlayerMovement::Update()
{
	if ((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000))
	{
		//m_ParentObject->m_Position.x = m_ParentObject->m_Position.x - *m_XSpeed;
		m_RigidBody->m_Acceleration.x = -*m_XSpeed;
	}
	else if ((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000))
	{
		//m_ParentObject->m_Position.x = m_ParentObject->m_Position.x + *m_XSpeed;
		m_RigidBody->m_Acceleration.x = *m_XSpeed;
	}
	else
	{
		m_RigidBody->m_Acceleration.x = 0;
	}
	if ((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000))
	{
		//m_ParentObject->m_Position.y = m_ParentObject->m_Position.y + *m_YSpeed;
		m_RigidBody->m_Acceleration.y = *m_YSpeed;
	}
	else if ((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000))
	{
		//m_ParentObject->m_Position.y = m_ParentObject->m_Position.y - *m_YSpeed;
		m_RigidBody->m_Acceleration.y = -*m_YSpeed;
	}
	else
	{
		m_RigidBody->m_Acceleration.y = 0;
	}
}
PlayerMovement::PlayerMovement(GameObject* parentObject, float xSpeed, float ySpeed) : Component(parentObject)
{
	m_RigidBody = dynamic_cast<RigidBody*>(parentObject->GetComponent("RigidBody"));
	m_RigidBody->m_Friction = 0.3f;
	*m_YSpeed = ySpeed;
	*m_XSpeed = xSpeed;
}

PlayerMovement::~PlayerMovement()
{
}

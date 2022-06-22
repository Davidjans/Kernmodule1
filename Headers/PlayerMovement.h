#pragma once
#include "Component.h"
#include "RigidBody.h"

class PlayerMovement :
	public Component
{
public:
	float* m_XSpeed = new float(2);
	float* m_YSpeed = new float(2);
	RigidBody* m_RigidBody;
	void Update() override;
	PlayerMovement(GameObject* parentObject, float xSpeed, float ySpeed);
	~PlayerMovement();
};

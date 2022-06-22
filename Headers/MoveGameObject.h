#pragma once
#include "Component.h"
class MoveGameObject :
	public Component
{
public:
	float* m_XSpeed = new float(2);
	float* m_YSpeed = new float(2);
	void Update() override;
	MoveGameObject(GameObject* parentObject, float xSpeed, float ySpeed);
	~MoveGameObject() override;
};

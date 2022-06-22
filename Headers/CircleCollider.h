#pragma once
#include "Collider.h"
class CircleCollider :
	public Collider
{
public:
	float* m_Radius = new float(10.5f);
	CircleCollider(GameObject* parentObject, float radius);
	~CircleCollider();
};

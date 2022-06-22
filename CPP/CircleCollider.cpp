#include "CircleCollider.h"
CircleCollider::CircleCollider(GameObject* parentObject, float radius) : Collider(parentObject)
{
	*m_Radius = radius;
}

CircleCollider::~CircleCollider()
{
}
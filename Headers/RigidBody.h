#pragma once
#include "Component.h"
#include "Vector2.h"

class RigidBody :
    public Component
{
public:
    void Update() override;
    RigidBody(GameObject* parentObject);
    ~RigidBody() override;
    Vector2 m_Velocity = Vector2(0, 0);
    Vector2 m_Acceleration = Vector2(0, 0);
    float m_Mass = 0.1f;
    float m_Friction = 0.001f;
    void AddForce(float xForce, float yForce, bool divideByMass = true);
    void MoveObject();
    void CheckHitBorder();
};




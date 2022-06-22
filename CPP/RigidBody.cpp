#include "RigidBody.h"

#include "BaseStuff.h"
#include "GameManager.h"
#include "MathStuff.h"

void RigidBody::Update()
{
	Component::Update();
    AddForce(m_Acceleration.x, m_Acceleration.y);
    MoveObject();
    CheckHitBorder();
}

RigidBody::RigidBody(GameObject* parentObject): Component(parentObject)
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::AddForce(float xForce, float yForce, bool divideByMass)
{
    float dt = BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
    xForce *= 1000;
    yForce *= 1000;
    if(divideByMass)
    {
        float xForceToAdd = xForce / m_Mass;
        float yForceToAdd = yForce / m_Mass;
        m_Velocity.x = m_Velocity.x + xForceToAdd * dt;
        m_Velocity.y = m_Velocity.y + yForceToAdd * dt;
    }
    else
    {
        m_Velocity.x = m_Velocity.x + xForce * dt;
        m_Velocity.y = m_Velocity.y + yForce * dt;
    }
    
}

void RigidBody::MoveObject()
{
    m_ParentObject->m_Position.x = m_ParentObject->m_Position.x + m_Velocity.x * BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
    m_ParentObject->m_Position.y = m_ParentObject->m_Position.y + m_Velocity.y * BaseStuff::GetInstance()->GetDeltaTime().asSeconds();
    m_Velocity.x += -m_Velocity.x * m_Friction;
    m_Velocity.y += -m_Velocity.y * m_Friction;
}

void RigidBody::CheckHitBorder() {
    if (m_ParentObject->m_Position.x >= GameManager::GetInstance()->m_RenderWindow->getSize().x||
        m_ParentObject->m_Position.x <= 0.f)
    {
        m_ParentObject->m_Position.x -= m_Velocity.x / 20;
        m_Velocity.x = m_Velocity.x * -1;
    }
}
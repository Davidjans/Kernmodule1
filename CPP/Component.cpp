#include "Component.h"

void Component::Start()
{
}

void Component::Update()
{
}

void Component::OnCollisionEnter(Collider* col)
{
}

void Component::OnCollisionStay(Collider* col)
{
}

void Component::OnCollisionExit(Collider* col)
{
}

void Component::OnTriggerEnter(Collider* col)
{
}

void Component::OnTriggerStay(Collider* col)
{
}

void Component::OnTriggerExit(Collider* col)
{
}

Component::Component(GameObject* parentObject)
{
	m_ParentObject = parentObject;
}

Component::~Component() = default;

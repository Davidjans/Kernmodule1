#pragma once
class Collider;
class GameObject;

class Component
{
public:
	bool m_Active = true;
	bool m_Delete = false;
	GameObject* m_ParentObject;
	virtual void Start();
	virtual void Update();
	virtual void OnCollisionEnter(Collider* col);
	virtual void OnCollisionStay(Collider* col);
	virtual void OnCollisionExit(Collider* col);
	virtual void OnTriggerEnter(Collider* col);
	virtual void OnTriggerStay(Collider* col);
	virtual void OnTriggerExit(Collider* col);
	Component(GameObject* parentObject);
	virtual ~Component();
};

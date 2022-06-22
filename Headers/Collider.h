#pragma once
#include <SFML/Graphics.hpp>
#include <DirectXMath.h>
#include "Enums.h"
#include <iostream>
#include "Component.h"
//class Component;
class GameObject;
class Collider :
	public Component
{
public:
	bool m_IsTrigger = false;
	sf::Vector3f* m_OffsetFromPivot = new sf::Vector3f(0, 0, 0);
	std::vector<Collider*>* m_InCollisionWith = new std::vector<Collider*>;
	void OnCollisionEnter(Collider* col) override;
	void OnCollisionStay(Collider* col) override;
	void OnCollisionExit(Collider* col) override;
	void OnTriggerEnter(Collider* col) override;
	void OnTriggerStay(Collider* col) override;
	void OnTriggerExit(Collider* col) override;
	void Collide(Collider* col);
	bool CheckAlreadyCollidingWithObject(Collider* col);
	void CheckNoCollide(Collider* col);
	Collider(GameObject* parentObject);

	~Collider();
private:
	bool CheckIfNotCollider(Component* thingToCheck);
};
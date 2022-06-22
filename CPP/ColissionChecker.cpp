#include "ColissionChecker.h"
#include "CircleCollider.h"
#include "BaseStuff.h"
#include <iostream>
#include "GameObject.h"
#include "Collider.h"
#include <iterator>
#include "Enums.h"
#include "Collider.h"
CollisionChecker* CollisionChecker::m_ManagerInstance = new CollisionChecker();

CollisionChecker* CollisionChecker::GetInstance()
{
	if (m_ManagerInstance == nullptr)
		m_ManagerInstance = new CollisionChecker();
	return m_ManagerInstance;
}

void CollisionChecker::CheckWhatCollided()
{
	for (auto& objectColliderPair : m_CollidersPerGameObject)
	{
		for (auto& secondObjectColliderPair : m_CollidersPerGameObject)
		{
			if (secondObjectColliderPair.first == objectColliderPair.first)
				continue;
			bool canHitLayer = false;

			int secondIndex = BaseStuff::GetIndexOf(m_LayerMatrix.at(objectColliderPair.first->m_ObjectLayer), secondObjectColliderPair.first->m_ObjectLayer);

			if (secondIndex != -1) {
				canHitLayer = true;
				//std::cout << "can hit this layer" << std::endl;
			}
			else
			{
				//std::cout << "could not hit this layer" << std::endl;
				break;
			}
			// for now i'm only gonna do this with circle colliders so that's the only check i will have here.
			Collider* tempColOne = objectColliderPair.second;
			Collider* tempColTwo = secondObjectColliderPair.second;
			CircleCollider& colOne = *dynamic_cast<CircleCollider*>(tempColOne);
			CircleCollider& colTwo = *dynamic_cast<CircleCollider*>(tempColTwo);
			float distance = BaseStuff::CalculateDistance(colOne.m_ParentObject->m_Position.x, colOne.m_ParentObject->m_Position.y,
				colTwo.m_ParentObject->m_Position.x, colTwo.m_ParentObject->m_Position.y);

			if (distance - (*colOne.m_Radius + *colTwo.m_Radius) < 0) {
				colOne.Collide(secondObjectColliderPair.second);
				//std::cout << *colOne->m_ParentObject->m_ObjectName << " HIT " << *colTwo->m_ParentObject->m_ObjectName << std::endl;
			}
			else {
				colOne.CheckNoCollide(secondObjectColliderPair.second);
				//std::cout << *colOne->m_ParentObject->m_ObjectName << " MISSED " << *colTwo->m_ParentObject->m_ObjectName << std::endl;
			}
		}
	}
			
}

CollisionChecker::CollisionChecker()
{
	m_LayerMatrix.insert({ Enums::Default, std::vector<Enums::Layer>() });
	m_LayerMatrix.insert({ Enums::Player, std::vector<Enums::Layer>() });
	m_LayerMatrix.insert({ Enums::Enemy, std::vector<Enums::Layer>() });
	m_LayerMatrix.insert({ Enums::Enviroment, std::vector<Enums::Layer>() });
	for (auto& layerMatrixPair : m_LayerMatrix)
	{
		m_LayerMatrix.at(layerMatrixPair.first).push_back(Enums::Default);
		m_LayerMatrix.at(layerMatrixPair.first).push_back(Enums::Player);
		m_LayerMatrix.at(layerMatrixPair.first).push_back(Enums::Enemy);
		m_LayerMatrix.at(layerMatrixPair.first).push_back(Enums::Enviroment);
	}
	m_LayerMatrix.at(Enums::Enemy).erase(m_LayerMatrix.at(Enums::Enemy).begin() + 2);

}

CollisionChecker::~CollisionChecker()
{
}

void CollisionChecker::DeleteGameObject(GameObject* object)
{
	m_CollidersPerGameObject.erase(object);
}

void CollisionChecker::DeleteComponent(GameObject* parentObject, Collider* collider)
{
	m_CollidersPerGameObject.erase(parentObject);
}

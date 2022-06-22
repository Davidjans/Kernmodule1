#include "GameObject.h"

#include "BaseStuff.h"
#include "GameManager.h"
Component* GameObject::GetComponent(std::string typeToGet)
{
	Component* componentToGet = NULL;
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		Component& component1 = *m_Components[i];
		std::string nameToCompare = BaseStuff::SplitString(typeid(component1).name(),std::string(" ").at(0)).at(1);
		if (nameToCompare == typeToGet)
		{
			componentToGet = m_Components.at(i);
			break;
		}
	}

	return componentToGet;
}

void GameObject::Update()
{
	for (size_t c = 0; c < m_Components.size(); c++)
	{
		m_Components.at(c)->Update();
		if (m_Delete)
			return;
	}
	for (size_t c = 0; c < m_Components.size(); c++)
	{
		if (m_Components.at(c)->m_Delete) {
			delete m_Components.at(c);
		}
	}
}

void GameObject::SetLayer(Enums::Layer layerToSetTo)
{
	m_ObjectLayer = layerToSetTo;
}

GameObject::GameObject()
{
	m_GameManager = GameManager::GetInstance();
	m_GameManager->m_GameObjects.push_back(this);
}

GameObject::~GameObject()
{
	for (size_t i = 0; i < m_Components.size(); i++)
	{
		delete m_Components.at(i);
	}
}

void GameObject::AddComponent(Component* componentToAdd)
{
	m_Components.push_back(componentToAdd);
}
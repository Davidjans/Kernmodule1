#pragma once
#include "Component.h"
#include <iostream>
#include <vector>
#include <string>
#include "Enums.h"
#include "Vector2.h"
class GameManager;
class GameObject
{
public:
	bool m_Active = true;
	bool m_Delete = false;
	Vector2 m_Position = Vector2(0, 0);
	std::string m_ObjectName = "GameObject";
	std::vector<Component*> m_Components;
	Component* GetComponent(std::string typeToGet);
	GameManager* m_GameManager;
	Enums::Layer m_ObjectLayer = Enums::Default;
	void Update();
	void AddComponent(Component* componentToAdd);
	void SetLayer(Enums::Layer layerToSetTo);
	GameObject();
	~GameObject();
};
#include "BaseScene.h"
#include "GameManager.h"
void BaseScene::Update()
{
}
void BaseScene::LoadScene()
{
}

void BaseScene::UnloadScene()
{
}

BaseScene::BaseScene()
{
	m_GameManager = GameManager::GetInstance();
}

BaseScene::~BaseScene()
{
}
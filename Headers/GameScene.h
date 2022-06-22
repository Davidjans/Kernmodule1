#pragma once
#include "BaseScene.h"
class GameScene :
	public BaseScene
{
public:
	void LoadScene() override;
	void UnloadScene() override;
	void Update() override;
};

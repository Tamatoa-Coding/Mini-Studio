#pragma once

#include "Scene.h"

class Enemy;
class DummyEntity;
class Player;

class SceneGame : public Scene
{
	DummyEntity* mPlayer;
	Enemy* pEnemy;
	Player* pPlayer;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};


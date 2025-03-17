#pragma once

#include "Scene.h"

class Enemy;
class DummyEntity;
class Player;

class SceneGame : public Scene
{
	Player* pPlayer;
	Enemy* pEnemy;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};


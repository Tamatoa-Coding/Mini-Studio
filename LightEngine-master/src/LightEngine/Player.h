#pragma once
#include "PhysicalEntity.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>

class Player : public PhysicalEntity
{
	bool isJumping = false;
	int MaxLife = 3;
	int Life = MaxLife;
	sf::Clock mClockDoubleJump;
	float jumpCooldown = 0.5f;
	
public:
	void Reset();
	void Jump();
	void Move();
	void Move(float deltaTime, int key);
	void TakeHit();
	int GetLife() { return Life; }
	void OnUpdate() override;
};


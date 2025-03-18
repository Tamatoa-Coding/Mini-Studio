#pragma once
#include "PhysicalEntity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullets;

class Player : public PhysicalEntity
{
	bool mGravity = false;
	float mGravitySpeed = 0.f;
	bool isJumping = false;
	int jumpCount = 0;

	sf::Clock mClockDoubleJump;
	float jumpCooldown = 0.5f;
	int lastDirection = 1;

public:

	void Jump();
	void TakeHit();

	int getLastDirection();
	void setLastDirection(int dir);
	void Move(float deltaTime, int key);
	void Reset();
	void Dash(float deltaTime);

	int mLife = MaxLife;
	int MaxLife = 3;
	float dashTime = 0.2f;
	float dashTimer = 0.0f;
	float dashCooldown;
	float shootCooldown = 0.5f;
};


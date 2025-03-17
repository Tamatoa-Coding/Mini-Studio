#include "Player.h"

int Player::getLastDirection()
{
	return lastDirection;
}

void Player::setLastDirection(int dir)
{
	lastDirection = dir;
}

void Player::Reset() {
	sf::Vector2f pPosCenter = sf::Vector2f(GameManager::Get()->GetScene()->GetWindowWidth(),
		GameManager::Get()->GetScene()->GetWindowHeight());
	SetPosition(pPosCenter.x / 2, pPosCenter.y / 4);
	mGravitySpeed = 0;
}


void Player::Move(float deltaTime, int key){
	SetDirection(key, 0, 250);
}

void Player::Jump()
{
	sf::Vector2f mPos = GetPosition();

		if (jumpCount < 2)
		{
			mGravitySpeed = -200;
			isJumping = true;
			jumpCount++;
		}

		else if (mPos.y == 600)
		{
			jumpCount = 0;
		}

	if (!sf::Joystick::isButtonPressed(0, 1) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isJumping = false;
	}
}

void Player::TakeHit()
{
	mLife--;
	if (mLife <= 0)
	{
		//GameOver
	}
}

void Player::Dash(float deltaTime)
{
		SetDirection(lastDirection, 0, 800); // droite ou gauche
}

#include "Player.h"

void Player::Reset()
{
	sf::Vector2f pPosCenter = sf::Vector2f(GameManager::Get()->GetScene()->GetWindowWidth(),
		GameManager::Get()->GetScene()->GetWindowHeight());
	SetPosition(pPosCenter.x / 2, pPosCenter.y / 4);
	mGravitySpeed = 0;
}

void Player::Jump()
{
	if (GetState() == TOP || mNbrJump >= 2 || mClockDoubleJump.getElapsedTime().asSeconds() < jumpCooldown)
		return;

	sf::Vector2f pPos = GetPosition(0.5f, 0.5f);
	SetPosition(pPos.x, pPos.y - 1);
	SetCollider(pPos.x, pPos.y - 1, mBoxCollider->ySize, mBoxCollider->xSize);
	mGravity = true;
	mGravitySpeed = -350;
	mNbrJump++;
	mClockDoubleJump.restart();

	/*sf::Vector2f mPos = GetPosition();

	if (sf::Joystick::isButtonPressed(0, 1) && !isJumping ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping)
	{
		if (jumpCount < 2)
		{
			mGravitySpeed = -225;
			isJumping = true;
			std::cout << "Jump" << std::endl;
			jumpCount++;
		}

		else if (mPos.y == 600)
		{
			jumpCount = 0;
		}

	}
	else if (!sf::Joystick::isButtonPressed(0, 1) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isJumping = false;
	}*/
}

void Player::Move()
{
	float vitesse = 2.f;
	if (sf::Joystick::isConnected(0)) {

		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		//Drift out 
		if (x > 0.f && x < 10.f || x < 0.f && x > -10.f)
		{
			x = 0.f;
		}
		//Boutton R2 Appuyé = sprint
		if (sf::Joystick::isButtonPressed(0, 7))
		{
			vitesse = vitesse * 1.5;
			std::cout << "Bouton 1" << std::endl;
		}
		SetDirection(x, 0, vitesse);
		std::cout << "X : " << x << std::endl;
	}
	else{
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::LShift)) {
			vitesse = vitesse * 1.5;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			SetPosition(GetPosition().x + 3 + vitesse, GetPosition().y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			SetPosition(GetPosition().x - 3 - vitesse, GetPosition().y);
		}
	}
}

void Player::Move(float deltatime, int key) {
	SetDirection(key, 0, 250);
}


void Player::TakeHit()
{
	//test life décrémentations
	//if (sf::Joystick::isButtonPressed(0, 3))
	//{
	//	Life--;
	//	if (Life <= 0)
	//	{
	//		//GameOver
	//	}
	//}

	Life--;
	if (Life <= 0)
	{
		//GameOver
	}

}

void Player::OnUpdate()
{
	float dt = GetDeltaTime();
	Fall(dt);
	Jump();
	Move();	
	//TakeHit();

}
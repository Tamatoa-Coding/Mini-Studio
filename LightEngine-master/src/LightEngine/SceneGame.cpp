#include "SceneGame.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

#include "Debug.h"

void SceneGame::OnInitialize()
{
	pPlayer = CreateRectangle<Player>(16,16, sf::Color::Red);
	pPlayer->SetPosition(640, 600);
	pPlayer->SetRigidBody(true);

	pEnemy = CreateRectangle<Enemy>(16,16, sf::Color::Blue);
	pEnemy->SetPosition(800, 600);
	pEnemy->SetRigidBody(true);
}

void SceneGame::OnEvent(const sf::Event& event)
{
	const AABBCollider* enemyCollider = pEnemy->GetCollider();
	const AABBCollider* playerCollider = pPlayer->GetCollider();

	if (pPlayer->IsColliding(*enemyCollider)) { //If player touches Enemy
		pPlayer->TakeHit(); //Player dies
	}

	if (pPlayer->GetPosition().y+16 <= pEnemy->GetPosition().y &&
		pEnemy->IsColliding(*playerCollider)) { // If player jumps on Enemy
		pEnemy->getHit(); //Enemy dies
	}
}

void SceneGame::OnUpdate()
{
	std::string text = "Life : " + std::to_string(pPlayer->GetLife());
	Debug::DrawText(10, 10, text, sf::Color::White);
}
#include "SceneGame.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Debug.h"
#include "Base.h"
#include <SFML/Graphics.hpp>

void SceneGame::OnInitialize()
{
	pPlayer = CreateEntity<Player>(20, sf::Color::Red);
	pPlayer->SetPosition(640, 600);
	pPlayer->SetRigidBody(true);

	pEnemy = CreateEntity<Enemy>(30, sf::Color::Blue);
	pEnemy->SetPosition(800, 600);
	pEnemy->SetRigidBody(true);
}

void SceneGame::OnEvent(const sf::Event& event)
{
	if (pPlayer->IsColliding(pEnemy)) { //If player touches Enemy
		pPlayer->TakeHit(); //Player dies
	}

	if ((-pPlayer->GetPosition().y + 600 + 40) >= pEnemy->GetRadius() &&
		pEnemy->IsColliding(pPlayer)) { // If player jumps on Enemy
		pEnemy->getHit(); //Enemy dies
	}
}

void SceneGame::OnUpdate()
{
    std::string text = "Life : " + std::to_string(pPlayer->GetLife());
    Debug::DrawText(10, 10, text, sf::Color::White);

}

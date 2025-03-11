#include "Enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(float speed) {
	moveSpeed = speed;
}

void Enemy::getHit() {
	Destroy();
}

void Enemy::wallCollide() {
	//Ici je teste out of bounds - faudra faire avec les murs quand on les aura
	if (GetPosition().x > 1280 - 30) {
		SetPosition(1280 - 30, GetPosition().y);
		direction = 'l';
	}
	else if (GetPosition().x < 0 + 30) {
		SetPosition(30, GetPosition().y);
		direction = 'r';
	}
}

void Enemy::OnUpdate() {
	SetPosition(GetPosition().x, 600);

	wallCollide();

	//If left, then goes left
	if (direction == 'l') {
		SetDirection(-100, 0, moveSpeed);
	}
	else { //else, go right
		SetDirection(100, 0, moveSpeed);
	}
}
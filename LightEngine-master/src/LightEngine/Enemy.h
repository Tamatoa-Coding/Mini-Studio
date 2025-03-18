#pragma once
#include "PhysicalEntity.h"
#include <SFML/Graphics.hpp>

class Enemy : public PhysicalEntity
{
public:
    void OnCollision(Entity* collidedWith) override;
    const AABBCollider* GetCollider() { return mBoxCollider; }

};

class Enemy :
    public PhysicalEntity
{
    bool mGravity = false;
    float mGravitySpeed = 0.f;
    bool isJumping = false;
    // ^ c'est au cas o� on veut faire un ennemi qui saute

    float moveSpeed = 1;
    char direction = 'r';

public:
    Enemy();
    Enemy(float speed);
    void getHit();
    void wallCollide();
    void OnUpdate() override;
};

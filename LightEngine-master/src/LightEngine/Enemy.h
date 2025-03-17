#pragma once
#include "PhysicalEntity.h"

class Enemy :
    public PhysicalEntity
{
    bool mGravity = false;
    float mGravitySpeed = 0.f;
    bool isJumping = false;
    // ^ c'est au cas où on veut faire un ennemi qui saute

    float moveSpeed = 1;
    char direction = 'r';

public:
    Enemy();
    Enemy(float speed);
    void getHit();
    void wallCollide();
    void OnUpdate() override;
};


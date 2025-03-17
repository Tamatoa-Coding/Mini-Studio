#pragma once
#include "Entity.h"

class ObjectEntity : public Entity
{

public:
	void OnInitialize() override;
	bool IsColliding(const AABBCollider& c1);
};


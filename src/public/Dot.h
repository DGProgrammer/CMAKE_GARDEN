#pragma once
#include "Entity.h"

class World;

class Dot : public Entity
{
public:
	Dot(World* world);
	virtual void update(float deltaTime) override;
};


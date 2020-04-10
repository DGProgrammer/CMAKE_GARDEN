#pragma once
#include "Entity.h"

class Dot : public Entity
{
public:
	Dot();
	virtual void update(float deltaTime) override;
};


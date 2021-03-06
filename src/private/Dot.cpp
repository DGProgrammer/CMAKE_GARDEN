#include "Dot.h"

Dot::Dot(World* world) : Entity({ 20,20 }, "res/textures/dot.png", world)
{
	setPosition(rand() % 800, 0);
}

void Dot::update(float deltaTime)
{
	//Entity::update(deltaTime); //Para no eliminar el comportamiento del padre

	auto pos = getPosition();
	pos.y += 100 * deltaTime;
	setPosition(pos);
}
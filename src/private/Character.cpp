#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#include "Character.h"
#include "Entity.h"
#include "Dot.h"
#include "World.h"

Character::Character(World* world) : Entity({ 100,100 }, "res/textures/maceta.png", world)
{
	setPosition({ 1, 600 });
}

void Character::update(float deltaTime)
{
	Entity* c = checkColision();
	if (c != nullptr) {

		printf("Collision!\n");
		m_world->removeEntity(c);
	}
}

void Character::onKeyDown(sf::Event::KeyEvent event)
{
	sf::Vector2f dir;
	sf::Vector2f finalPos;
	sf::Vector2f m_position = getPosition();

	if (event.code == sf::Keyboard::Key::Right)
	{
		dir.x += m_velocity;
	}

	if (event.code == sf::Keyboard::Key::Left)
	{
		dir.x += -m_velocity;
	}

	finalPos = m_position + dir;
	if (finalPos.x > 1 && finalPos.x < 700)
	{
		setPosition(finalPos);
	}
}




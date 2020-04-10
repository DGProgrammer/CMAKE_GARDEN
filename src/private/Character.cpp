#include <SFML/Window/Event.hpp>

#include "Character.h"

Character::Character() : Entity({ 100,100 }, "res/textures/maceta.png")
{
	setPosition({ 1, 600 });
	m_position = getPosition();
}

void Character::update(float deltaTime)
{
}

void Character::onKeyDown(sf::Event::KeyEvent event)
{
	sf::Vector2f dir;
	sf::Vector2f finalPos;
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
		m_position = finalPos;
		setPosition(m_position);
	}
}



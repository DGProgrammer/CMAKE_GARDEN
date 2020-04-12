#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#include "Character.h"
#include "Entity.h"
#include "Dot.h"

Character::Character() : Entity({ 100,100 }, "res/textures/maceta.png")
{
	setPosition({ 1, 600 });
	m_position = getPosition();
}

void Character::update(float deltaTime)
{
	checkColision();
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

void Character::checkColision()
{
	for (Entity* e : *m_entities)
	{
		Dot* d = dynamic_cast<Dot*>(e);
		if (d != nullptr)
		{
			sf::Vector2f distance((getPosition() - d->getPosition()));
			if (distance.y < 1 && distance.y > -1)
			{
				if (distance.x < 1)
				{
					if (rect().contains(d->getPosition()))
						printf("YA");
				}
			}
		}
	}
}


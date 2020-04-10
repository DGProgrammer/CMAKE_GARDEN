#pragma once
#include "Entity.h" 
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

class Character : public Entity
{
public:
	Character();
	virtual void update(float deltaTime) override;
	virtual void onKeyDown(sf::Event::KeyEvent event) override;

private:
	float m_velocity = 10;
	sf::Vector2f m_position;
};


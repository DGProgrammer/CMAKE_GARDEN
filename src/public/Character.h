#pragma once
#include "Entity.h" 
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

class World;

class Character : public Entity
{
public:
	Character(World* world);
	virtual void update(float deltaTime) override;
	virtual void onKeyDown(sf::Event::KeyEvent event) override;

private:
	//void checkColision();			// El concepto ver si una entidad colisiono con otra
									// no es algo exclusivo de Character, si no que Character
									// usa este concepto contra otras entidades
	float m_velocity = 10;
	//sf::Vector2f m_position;		// Heredar de sf::Transformable ya te da una posición
};


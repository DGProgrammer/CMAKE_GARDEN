#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

#include "Entity.h"
#include "World.h"

using namespace sf;
using namespace std;

Entity::Entity(const Entity & e)
	: p_shape(new RectangleShape(*e.p_shape)), m_size(e.m_size), m_texture(new Texture(*e.m_texture)), m_world(e.m_world)
{
	setPosition(e.getPosition());
	setRotation(e.getRotation());
	setScale(e.getScale());
}

Entity::Entity(sf::Vector2i size, const char* fileName, World* world) :
	p_shape(new RectangleShape({ (float)size.x, (float)size.y })),
	m_size(size),
	m_texture(new Texture),
	m_world(world)
{
	m_texture->loadFromFile(fileName);
	p_shape->setTexture(m_texture);
}

Entity::~Entity()
{
	if (m_texture == nullptr)
		delete m_texture;
}

sf::FloatRect Entity::getRect()
{
	// No puedes devolver una referencia de un objeto destruido!!
	// cuando haces getGlobalBounds generas una variable volatil
	// que se destruye al final de este ambito.
	//
	// Otra cosa seria que guardaras el resultado en una variable
	// dentro de esta clase y entonces devolvieras una referecia
	// de esa variable

	sf::FloatRect bounds = p_shape->getGlobalBounds();
	bounds.left = getPosition().x;
	bounds.top  = getPosition().y;
	return bounds;
}

void Entity::update(float deltaTime)
{
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*p_shape, states);
}

void Entity::onKeyDown(sf::Event::KeyEvent event)
{
}

Entity* Entity::checkColision()
{
	auto rect = getRect();
	for (Entity* e : m_world->getEntities())
	{
		if (e == this) continue;

		auto otherRect = e->getRect();
		if (rect.contains(e->getPosition())) {
			return e;
		}
	}
	return nullptr;
}

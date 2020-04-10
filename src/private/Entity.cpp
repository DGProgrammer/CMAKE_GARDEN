#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

#include "Entity.h"

using namespace sf;
using namespace std;

Entity::Entity(const Entity & e)
	: p_shape(new RectangleShape(*e.p_shape)), m_size(e.m_size), m_texture(new Texture(*e.m_texture))
{
	setPosition(e.getPosition());
	setRotation(e.getRotation());
	setScale(e.getScale());
}

Entity::Entity(sf::Vector2i size, const char* fileName) :
	p_shape(new RectangleShape({ (float)size.x, (float)size.y })),
	m_size(size),
	m_texture(new Texture)
{
	m_texture->loadFromFile(fileName);
	p_shape->setTexture(m_texture);
}

Entity::~Entity()
{
	if (m_texture == nullptr)
		delete m_texture;
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

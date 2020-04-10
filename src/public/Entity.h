#pragma once
#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

//======================
//Forward declaration
//namespace sf {
//	class RectangleShape;
//}

//======================
//Class

typedef std::unique_ptr<sf::RectangleShape> RecShapPtr;
typedef std::unique_ptr<sf::Texture> TexPtr;

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(const Entity& e);
	Entity(sf::Vector2i size, const char* fileName);
	~Entity();

	virtual void update(float deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void onKeyDown(sf::Event::KeyEvent event);

private:
	RecShapPtr p_shape;
	sf::Vector2i m_size;
	sf::Texture* m_texture;
};




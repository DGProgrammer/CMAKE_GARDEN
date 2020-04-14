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
class World;

//======================
//Class

typedef std::unique_ptr<sf::RectangleShape> RecShapPtr;
typedef std::unique_ptr<sf::Texture> TexPtr;

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(const Entity& e);
	Entity(sf::Vector2i size, const char* fileName, World* world);
	
	//std::vector<Entity*>* m_entities;   // La lista de entidades la controla el mundo
									      // No es un concepto incorrecto si quieres
										  // hijos en tus entidades, pero en este caso
										  // las gotas no son hijas del Character
										  // si no del mundo

	~Entity();

	sf::FloatRect getRect();
	virtual void update(float deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void onKeyDown(sf::Event::KeyEvent event);
	
	

protected:
	Entity* checkColision();

private:
	RecShapPtr p_shape;
	sf::Texture* m_texture;
	sf::Vector2i m_size;

protected:
	World* m_world;
};




#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
 
#include "World.h"
using namespace sf;

int main()
{
	VideoMode mode(800, 800);
	RenderWindow window(mode, "Pot game");

	Clock clock;

	World world;
	world.init();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		auto seconds = clock.restart().asSeconds();

		world.update(seconds);
		window.clear();
		window.draw(world);
		window.display();
	}


	return 0;
}
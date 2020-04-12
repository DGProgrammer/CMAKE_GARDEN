#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "Entity.h"

class World : public sf::Drawable
{
public:
	World();

	void init();
	void update(float deltaTime);
	void onKeyDown(sf::Event::KeyEvent event);

	std::vector<Entity*>& getEntities();
	void removeEntity(Entity* ptr);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	void spawnCharacter();
	void spawnDots();

private:
	/** current entities inside the world*/
	std::vector<Entity*> m_entities;
	sf::Clock clock;

	float leftTime;
	float DotsSpawnRatio;
	bool bIsSpawning;
};

//void foo()
//{
//	World w;
//	w.a.reserve(2);
//	
//	w.a.push_back(1);
//
//}


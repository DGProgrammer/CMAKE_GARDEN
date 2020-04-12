#include "World.h"
#include "Entity.h"
#include "Dot.h"
#include "Character.h"

World::World() : DotsSpawnRatio(2), leftTime(DotsSpawnRatio), bIsSpawning(false)
{
}

void World::init()
{
	spawnCharacter();
	bIsSpawning = true;
}

void World::update(float deltaTime)
{
	// Spawning dots (enemies)
	leftTime -= deltaTime;
	if (bIsSpawning && leftTime <= 0) {

		leftTime = DotsSpawnRatio;
		spawnDots();
	}

	leftTime = fmax(0, leftTime);


	// Call update on each entity in the world
	for (Entity* e : m_entities)
	{
		(e)->update(deltaTime);
	}
}

void World::onKeyDown(sf::Event::KeyEvent event)
{
	for (Entity* e : m_entities)
	{
		(e)->onKeyDown(event);
	}
}

void World::spawnCharacter()
{
	Character* character = new Character;
	m_entities.push_back(character);
	character->m_entities = &m_entities;
}

void World::spawnDots()
{
	Dot* dot = new Dot;
	m_entities.push_back(dot);
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//for (auto& e : m_entities)
	//{
	//	e.draw(target, states);
	//}


	for (std::vector<Entity*>::const_iterator it = m_entities.begin(); it != m_entities.end(); ++it) {

		(*it)->draw(target, states);
	}
}

#include "World.h"
#include "Entity.h"
#include "Dot.h"
#include "Character.h"

World::World() : DotsSpawnRatio(2), leftTime(2), bIsSpawning(false)
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

std::vector<Entity*>& World::getEntities()
{
	return m_entities;
}

void World::removeEntity(Entity* ptr)
{
	// Muchas funciones en C++ piden punteros del principio
	// y el final de listas de datos. Hay funciones que piden 
	// esos punteros para añadir un lambda (una función dentro del parametro)
	// que condiciona si se debe o no eliminar (true para si, false para no)
	// Como los punteros no son mas que direcciones de memoria
	// comparar dos punteros es comparar si estan en la misma ubitación
	// y si ese es el caso, entonces el elemento que queremos eliminar (true)
	//
	// Otra opcion habria sido iterar por todos con un bucle pregutando si son iguales
	m_entities.erase(
	std::remove_if(m_entities.begin(), m_entities.end(),
		[&](Entity* ref) {
			return ref == ptr;
		}
	));
}

void World::spawnCharacter()
{
	Character* character = new Character(this);
	m_entities.push_back(character);

	//character->m_entities = &m_entities;				// En el momento que le pasas la lista
														// a Character, World pierde la responsabilidad
														// de esos dato, ya que ahora hay dos trozos de codigo tratando los mismos datos. 
														// Esto a la larga crea problemas de diseño
}

void World::spawnDots()
{
	Dot* dot = new Dot(this);
	m_entities.push_back(dot);
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (std::vector<Entity*>::const_iterator it = m_entities.begin(); it != m_entities.end(); ++it) {

		(*it)->draw(target, states);
	}
}

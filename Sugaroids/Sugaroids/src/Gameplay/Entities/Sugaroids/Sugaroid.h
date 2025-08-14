#pragma once

#include <raylib.h>
#include <list>

#include "Gameplay/Entities/Textured.h"

enum class Enemies
{
	Sugaroid,
	Cometkie,
	Chip,
	None
};

namespace Sugaroids
{
	class Sugaroid : public Textured
	{

	public:

		Sugaroid();
		Sugaroid(Vector2 position, Vector2 targetPos);
		virtual ~Sugaroid() override;

	};

	Sugaroid CreateEnemy(Vector2 playerPosition);
	void Spawner(float& spawnTimer, float sugaroidsSpawnRate, float deltaTime, Vector2 playerPos, std::list<Sugaroid>& sugaroids);
}

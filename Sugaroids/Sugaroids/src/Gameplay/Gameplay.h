#pragma once

#include <raylib.h>
#include <list>

#include "ProgramState.h"
#include "Gameplay/Entities/Player/Player.h"
#include "Gameplay/Entities/Player/powerUps.h"

namespace GameManager
{
	class Gameplay : public ProgramState
	{
	public:

		Gameplay();
		~Gameplay();

		void Init() override;

		void Update(Vector2 mouse) override;

		void Draw() override;

		void Unload() override;

	private:

		float deltaTime = 0.0f;
		Vector2 mouse = { 0.0f, 0.0f };

		bool gameOver = false;
		int points = 0;

		float sugaroidsSpawnTime = 0.0f;
		float spawnTime = 0.0f;

		std::list<Entity*> entities;
		Player::Player player;

		void Reset();

		void DificultyIncreas();

		PowerUpList PowerUpRulete();

		bool DidPlayerDied();
	};
}
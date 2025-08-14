#pragma once

#include <raylib.h>
#include <vector>

#include "ProgramState.h"
#include "Menus/Pause/Pause.h"
#include "Gameplay/Entities/Player/Player.h"
#include "Gameplay/Entities/Player/powerUps.h"

namespace GameManager
{
	class Gameplay : public ProgramState
	{
	private:

		float deltaTime = 0.0f;

		Font* font;

		bool gameOver = false;
		bool pause = false;
		int points = 0;

		float sugaroidsSpawnTime = 0.0f;
		float spawnTime = 0.0f;

		std::vector<Physics*> entities;
		Player::Player player;

		Pause pauseMenu;

		void Reset();

		void DificultyIncreas();

		PowerUpList PowerUpRulete();

		bool DidPlayerDied();

	public:

		Gameplay();
		Gameplay(MenuOptions& gameState, Font& font);
		~Gameplay();

		void Init() override;

		void Update(Vector2 mouse) override;

		void Draw() override;

		void Unload() override;
	};
}
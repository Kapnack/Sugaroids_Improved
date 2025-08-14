#include "Gameplay.h"

GameManager::Gameplay::Gameplay()
{
}

GameManager::Gameplay::Gameplay(MenuOptions& gameState, Font& font)
{
	this->font = &font;

	pauseMenu = Pause(gameState, font);
}

GameManager::Gameplay::~Gameplay()
{
}

void GameManager::Gameplay::Init()
{
	pauseMenu.Init();
	Reset();
}

void GameManager::Gameplay::Update(Vector2 mouse)
{
	deltaTime = GetFrameTime();

	if (IsKeyPressed(KEY_ESCAPE))
		pause != pause;

	if (pause)
	{
		pauseMenu.Update(mouse);
		return;
	}

	player.Movement(deltaTime);

	if (player.DidShoot())
		entities.push_back(player.Shoot());

	for (Physics* physic : entities)
	{
		physic->Movement(deltaTime);

		for (Physics* otherPhysic : entities)
			physic->Collition(otherPhysic->GetPosition(), otherPhysic->GetRadius());
	}

}

void GameManager::Gameplay::Draw()
{
	if (gameOver)
	{
		//Scene::DrawGameOver(gameState, font);

		//GameManager::ShouldResetMatch(gameState, player, bullets, sugaroids, gameOver, points, sugaroidsSpawnRate, spawnTimer);
	}
	else
	{
		player.Draw();

		for (Physics* entity : entities)
			entity->Draw();

		if (pause)
			pauseMenu.Draw();


		if (player.levelingUp && !allBoostsUnlocked)
		{
			Scene::DrawPowerUpUnlockHud(player.lastPowerUnlock, player.levelingUp, font);
		}

		DrawTextEx(font, pointsText.c_str(), Vector2{ 0,0 }, scoreFontSize, 0, BLACK);
		DrawTextEx(font, playerLives.c_str(), Vector2{ 0, 20 }, scoreFontSize, 0, BLACK);

	}
}

void GameManager::Gameplay::Unload()
{
	Reset();
}

void GameManager::Gameplay::Reset()
{
	for (Entity* entity : entities)
	{
		delete entity;
	}

	entities.clear();

	points = 0;

	spawnTime = 0;

	sugaroidsSpawnTime = 2;

	player = Player::Player{};

	gameOver = false;
}

void GameManager::Gameplay::DificultyIncreas()
{
	sugaroidsSpawnTime -= sugaroidsSpawnTime * 0.1f;
}

PowerUpList GameManager::Gameplay::PowerUpRulete()
{
	switch (PowerUpList(rand() % 5))
	{
	case PowerUpList::BiggerBullets:
		return PowerUpList::BiggerBullets;
		break;

	case PowerUpList::X2BulletSpeed:
		return PowerUpList::X2BulletSpeed;
		break;

	case PowerUpList::X3Bullets:
		return PowerUpList::X3Bullets;
		break;

	case PowerUpList::GuidedMissiles:
		return PowerUpList::GuidedMissiles;
		break;

	default:
		return PowerUpList::None;
		break;
	}
}

bool GameManager::Gameplay::DidPlayerDied()
{
	//TODO: Implement player function to return the data
	return false;
}

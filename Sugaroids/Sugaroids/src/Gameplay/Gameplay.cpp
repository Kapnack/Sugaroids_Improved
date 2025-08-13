#include "Gameplay.h"

GameManager::Gameplay::Gameplay()
{
}

GameManager::Gameplay::~Gameplay()
{
}

void GameManager::Gameplay::Init()
{
	Reset();
}

void GameManager::Gameplay::Update(Vector2 mouse)
{
	deltaTime = GetFrameTime();

	player.Movement(deltaTime);

	if (player.DidShoot())
		entities.push_back(player.Shoot());

}

void GameManager::Gameplay::Draw()
{
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

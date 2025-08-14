#pragma once

#include <raylib.h>
#include <list>
#include <functional>

#include "Gameplay/Entities/Textured.h"
#include "Gameplay/Entities/Entity.h"
#include "powerUps.h"
#include "Gameplay/Entities/Sugaroids/sugaroid.h"
#include "Gameplay/Entities/Bullets/bullet.h"
#include "Gameplay/Entities/Bullets/Missile/Missile.h"

namespace Player
{
	class Player : public Textured
	{
	private:

		int lives = 3;

		Vector2 targetPos = {};
		Vector2 directionVector = {};
		float directionLength = 0;
		float maxSpeed = 300.0f;

		float invisibility = 0;

		int bulletBuffer = 0;
		float fireCooldown = 0;

		float blinkFrequency = 0.5f;
		float blinkAmplitude = 1.5f;

		float EXP = 0;
		int level = 0;
		bool levelingUp = false;

		PowerUpList lastPowerUnlock = PowerUpList::None;

		PowerUps boost = {};

		Sound* hurt = nullptr;
		Sound* shoot = nullptr;

		void KeepInBounds();

	public:

		Player();
		Player(Vector2 position, float radius, Texture2D& texture);
		~Player() override;

		void Movement(float deltaTime) override;

		bool IsDead();

		bool DidShoot();
		Bullet::Bullet* Shoot();
	};
}

#include "Player.h"

#include <cmath>

#include "Program.h"
#include "Gameplay/Entities/Bullets/bullet.h"
#include "Gameplay/Entities/Bullets/Missile/missile.h"

Player::Player::Player()
{
}

Player::Player::Player(Vector2 position, float radius, Texture2D& texture) : Textured(position, radius)
{
	SetTexure(texture);
}

Player::Player::~Player()
{
}

void Player::Player::Movement(float deltaTime)
{
	const float acceleration = 600.0f;

	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		targetPos = GetMousePosition();

		// Calcular dirección del jugador hacia el mouse
		directionVector = { targetPos.x - position.x, targetPos.y - position.y };
		directionLength = sqrtf(powf(directionVector.x, 2) + powf(directionVector.y, 2));

		// Normalizar la dirección
		if (directionLength > 0)
		{
			// Resistencia y movimiento curvo
			directionVector.x /= directionLength;
			directionVector.y /= directionLength;

			// Acelerar el jugador hacia la dirección del objetivo
			velocity.x += directionVector.x * acceleration * deltaTime;
			velocity.y += directionVector.y * acceleration * deltaTime;
		}
	}

	// Limitar velocidad máxima
	float currentSpeed = sqrtf(powf(velocity.x, 2) + powf(velocity.y, 2));
	if (currentSpeed > maxSpeed)
	{
		velocity.x /= currentSpeed * maxSpeed;
		velocity.y /= currentSpeed * maxSpeed;
	}

	Physics::Movement(deltaTime);

	if (IsOutOfBound())
		KeepInBounds();

}

bool Player::Player::IsDead()
{
	return lives <= 0;
}

bool Player::Player::DidShoot()
{
	return (IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

Bullet::Bullet* Player::Player::Shoot()
{
	if (boost.x3Bullets)
		bulletBuffer = 3;
	else
		bulletBuffer = 1;

	OnShoot();

	if (fireCooldown <= 0)
	{
		if (bulletBuffer > 0)
		{
			if (boost.guidedMissiles)
				return new Bullet::Bullet(position, angle);
			else
				return new Bullet::Missile(position, angle);

			bulletBuffer--;
			fireCooldown = 1;
		}
	}
	else
	{
		fireCooldown -= 0.5;
	}
}

void Player::Player::KeepInBounds()
{
	if (position.x < 0)
		position.x = static_cast<float>(Program::Program::screenWidth);

	if (position.x > Program::Program::screenWidth)
		position.x = 0;

	if (position.y < 0)
		position.y = static_cast<float>(Program::Program::screenHeight);

	if (position.y > Program::Program::screenHeight)
		position.y = 0;
}

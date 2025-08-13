#include <cmath>

#include "bullet.h"

Bullet::Bullet::Bullet()
{
}

Bullet::Bullet::Bullet(Vector2 position, float angle = 0.0f) : Physics(position, angle)
{
	float degressToRadians = angle * (PI / 180.0f);

	float directionX = cos(degressToRadians);
	float directionY = sin(degressToRadians);

	Vector2 velocity = { directionX * speed, directionY * speed };

	this->position = position;
	this->velocity = velocity;
	this->size = size;
	this->radius = size / 2;
	this->speed = speed;
	toDestroy = false;
}

Bullet::Bullet::~Bullet()
{
}

void Bullet::Bullet::SetSizeMultiplier(float scalar)
{
	size *= scalar;
}

void Bullet::Bullet::SetSpeedMultiplier(float scalar)
{
	size *= scalar;
}

void Bullet::Bullet::Movement(float deltaTime = 1)
{
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
}

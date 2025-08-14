#include <cmath>

#include "Bullet.h"

Bullet::Bullet::Bullet()
{
}

Bullet::Bullet::Bullet(Vector2 position, float radius, float angle = 0.0f) : Textured(position, radius, angle)
{
	this->position = position;
	this->velocity = velocity;
	this->size = size;
	this->radius = size / 2;
	this->speed = speed;
	toDestroy = false;

	float degressToRadians = angle * (PI / 180.0f);

	float directionX = cos(degressToRadians);
	float directionY = sin(degressToRadians);

	Vector2 velocity = { directionX * speed, directionY * speed };
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
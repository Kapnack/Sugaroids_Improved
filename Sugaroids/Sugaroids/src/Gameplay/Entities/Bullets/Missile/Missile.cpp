#include "Missile.h"

Bullet::Missile::Missile()
{
}

Bullet::Missile::Missile(Vector2 pos, float angle = 0.0f, Sugaroids::Sugaroid* target = nullptr)
	: Bullet(pos, angle)
{
	float closestDistance = std::numeric_limits<float>::max();

	this->target = target;
}

Bullet::Missile::~Missile()
{
}

void Bullet::Missile::Movement(float deltaTime = 1.0f)
{
	if (target != nullptr)
	{
		float angleToSugaroid = atan2f
		(
			target->position.y - position.y,
			target->position.x - position.x
		);

		velocity =
		{
			cosf(angleToSugaroid) * speed,
			sinf(angleToSugaroid) * speed
		};
	}

	Bullet::Movement(deltaTime);
}

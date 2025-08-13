#include "Physics.h"

#include <cmath>
#include "../../Program.h"

Physics::Physics()
{
}

Physics::Physics(Vector2 position, float radius, float angle = 0.0f) : Entity(position, angle), radius(radius)
{
}

Physics::~Physics()
{
}

void Physics::SetRadius(float radius)
{
	this->radius = radius;
}

void Physics::SetVelocity(Vector2 velocity)
{
	this->velocity = velocity;
}

void Physics::Movement(float deltaTime)
{
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
}

bool Physics::Collition(Vector2 position, float radius)
{
	float distance = sqrtf(powf(position.x - this->position.x, 2) + powf(position.y - this->position.y, 2));

	return distance <= (this->radius + radius);
}

bool Physics::IsOutOfBound()
{
	return
		position.x + radius < 0 ||
		position.x - radius > Program::Program::screenWidth ||
		position.y + radius < 0 ||
		position.y - radius > Program::Program::screenHeight;
}

#pragma once

#pragma once

#include "Entity.h"

class Physics : public Entity
{
protected:

	Vector2 velocity = { 0.0f, 0.0f };
	float speed = 600.0f;

	float radius = 1.0f;


public:

	Physics();
	Physics(Vector2 position, float radius, float angle = 0.0f);
	virtual ~Physics();

	void SetRadius(float radius);
	float GetRadius();

	void SetVelocity(Vector2 velocity);
	void SetSpeed(float speed);

	virtual void Movement(float deltaTime);

	virtual void Draw() = 0;

	bool Collition(Vector2 position, float radius);
	bool IsOutOfBound();

};




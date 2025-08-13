#pragma once

#pragma once

#include "Entity.h"

class Physics : public Entity
{
protected:

	Vector2 velocity = { 0.0f, 0.0f };
	float speed = 600.0f;

	float radius = 1.0f;

	void virtual Movement(float deltatime);

public:

	Physics();
	Physics(Vector2 position, float radius, float angle = 0.0f);
	virtual ~Physics();

	void SetRadius(float radius);
	void SetVelocity(Vector2 velocity);

	bool Collition(Vector2 position, float radius);
	bool IsOutOfBound();

};




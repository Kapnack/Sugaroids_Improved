#pragma once

#include <raylib.h>

class Entity
{
protected:

	Vector2 position = { 0.0f, 0.0f };

	float angle = 0.0f;
	float size = 32.0f;

public:

	Entity();
	Entity(Vector2 position, float angle = 0.0f);
	virtual ~Entity();

	void SetPosition(Vector2 position);
	void SetAngle(float angle);
	void SetSize(float size);
};
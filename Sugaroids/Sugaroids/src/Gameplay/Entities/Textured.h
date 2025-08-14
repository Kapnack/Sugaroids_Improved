#pragma once

#include "Physics.h"

class Textured : public Physics
{
protected:

	Texture2D* texture = nullptr;

public:

	Textured();
	Textured(Vector2 position, float radius, float angle = 0.0f);
	virtual ~Textured();

	void SetTexure(Texture& Texture);

	virtual void Draw();
};


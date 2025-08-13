#pragma once

#include <raylib.h>

class ProgramState
{
public:

	virtual void Init() = 0;

	virtual void Update(Vector2 mouse) = 0;

	virtual void Draw() = 0;

	virtual void Unload() = 0;
};


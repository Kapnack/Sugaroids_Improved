#pragma once

#include <raylib.h>
#include <vector>

class VFXPlayer
{
public:

	VFXPlayer();
	virtual ~VFXPlayer();

private:

	std::vector<Sound*> VFXs;
};


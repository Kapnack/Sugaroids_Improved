#pragma once

#include <raylib.h>

namespace Sounds
{
	struct GameSounds
	{
		Sound hurt = {};
		Sound boom = {};
		Sound die = {};
		Sound shoot = {};
		Sound levelUp = {};
	};

	class VFXManager
	{
	public:

		GameSounds vfx;

		VFXManager();
		~VFXManager();

		void Init();
		void Unload();
	};
}


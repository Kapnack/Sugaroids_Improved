#include "VFXManager.h"

Sounds::VFXManager::VFXManager()
{
}

Sounds::VFXManager::~VFXManager()
{
}

void Sounds::VFXManager::Init()
{
	vfx.hurt = LoadSound("../res/soundEffects/hurt.wav");
	vfx.boom = LoadSound("../res/soundEffects/boom.wav");
	vfx.die = LoadSound("../res/soundEffects/die.wav");
	vfx.shoot = LoadSound("../res/soundEffects/shoot.wav");
	vfx.levelUp = LoadSound("../res/soundEffects/levelUp.wav");
}

void Sounds::VFXManager::Unload()
{
	UnloadSound(vfx.hurt);
	UnloadSound(vfx.boom);
	UnloadSound(vfx.die);
	UnloadSound(vfx.shoot);
	UnloadSound(vfx.levelUp);
}

#include "TextureManager.h"

Textures::TextureManager::TextureManager()
{
}

Textures::TextureManager::~TextureManager()
{
}

void Textures::TextureManager::Init()
{
	textures.player = LoadTexture("../res/sprites/player/spaceship.png");
	textures.sugaroid = LoadTexture("../res/sprites/enemies/sugaroid.png");
	textures.cometkie = LoadTexture("../res/sprites/enemies/cometkie.png");
	textures.chip = LoadTexture("../res/sprites/enemies/chip.png");
	textures.bullets = LoadTexture("../res/sprites/bullets/star.png");
	textures.background = LoadTexture("../res/backgrounds/pacific.png");
	textures.gamesTitle = LoadTexture("../res/title.png");
}

void Textures::TextureManager::Unload()
{
	UnloadTexture(textures.player);
	UnloadTexture(textures.sugaroid);
	UnloadTexture(textures.cometkie);
	UnloadTexture(textures.chip);
	UnloadTexture(textures.bullets);
	UnloadTexture(textures.background);
	UnloadTexture(textures.gamesTitle);
}
#pragma once

#include <raylib.h>

namespace Textures
{
	struct GameTextures
	{
		Texture2D player = {};
		Texture2D sugaroid = {};
		Texture2D cometkie = {};
		Texture2D chip = {};
		Texture2D bullets = {};
		Texture2D background = {};
		Texture2D gamesTitle = {};
	};

	class TextureManager
	{
	public:

		GameTextures textures;

		TextureManager();
		~TextureManager();

		void Init();
		void Unload();
	};
}
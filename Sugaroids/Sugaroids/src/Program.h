#pragma once

#include <raylib.h>
#include <list>
#include <string>

#include "ProgramState.h"
#include "Managers/SoundTrackManager.h"
#include "Managers/VFXManager.h"
#include "Managers/TextureManager.h"
#include "Gameplay/Entities/Player/Player.h"
#include "Gameplay/Entities/Bullets/Bullet.h"

enum class MenuOptions
{
	MainMenu,
	Playing,
	GameOver,
	Rules,
	Credits,
	WantToExit,
	None,

	Replay,

	Resume,

	ConfirmExit,
	CancelExit,
	Exit

};

namespace Program
{
	class Program
	{
	private:

		float TitleFontSize = 100.0f;

		const std::string programName = "Sugaroids";

		double time = 0;

		Textures::TextureManager textureManager = {};
		SoundTrack::SoundTrackManager soundTrackManager;
		Sounds::VFXManager vfxManager;

		MenuOptions gameState = MenuOptions::MainMenu;
		MenuOptions previousMenu = MenuOptions::MainMenu;

		ProgramState* currentState = nullptr;
		ProgramState* previousState = nullptr;

		Font font;

		Vector2 mouse = { 0.0f, 0.0f };

		void SetState(MenuOptions state);

		void Loop();
		void Update();
		void Draw();
		void Unload();

		void CreateWindow();
		void InitAssets();
		void UnloadAssets();

		void ConfirmExit();

	public:

		static const int screenWidth;
		static const int screenHeight;

		Program();
		~Program();

		void Init();
	};
}


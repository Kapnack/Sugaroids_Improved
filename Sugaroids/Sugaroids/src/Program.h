#pragma once

#include <raylib.h>
#include <list>

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

		float TitleSize = titlesFontSize;

		const string programName = "Sugaroids";

		double time = 0;

		Textures::TextureManager textureManager = {};
		SoundTrack::SoundTrackManager soundTrackManager;
		Sounds::VFXManager vfxManager;

		MenuOptions gameState = MenuOptions::MainMenu;
		MenuOptions previousMenu = MenuOptions::MainMenu;

		Font font;

		std::list<Bullet::Bullet> bullets;
		std::list<Sugaroids::Sugaroid> sugaroids;
		std::list<Sugaroids::Sugaroid> sugaroidsChildList;


		bool pause = false;
		bool allBoostsUnlocked = false;

		float blinkFrequency = 0.5f;
		float blinkAmplitude = 1.5f;

		void SetState(MenuOptions state);

		void Loop();

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

		void Update();

		void Draw();

		void Unload();
	};
}


#pragma once

#include <raylib.h>

#include "Program.h"

namespace SoundTrack
{
	class SoundTrackManager
	{
	public:

		SoundTrackManager();
		~SoundTrackManager();

		void Init();

		void SetCurrentMusic(MenuOptions gameState);
		void Update();

		void Unload();

	private:

		static const int StopedMusic = 3;

		struct GameMusic
		{
			Music creditsMusic = {};
			Music mainMenuMusic = {};
			Music gameOverMusic = {};
			Music gamePlayMusic = {};
		};

		GameMusic music;

		Music* actualMusic = nullptr;
		Music* stopMusic[StopedMusic] = { nullptr };

		void StopMusic();

		void MainMenuOrganization();
		void GamePlayOrganization();
		void GameOverOrganization();
		void CreditsOrganization();
	};
}


#include "SoundTrackManager.h"

SoundTrack::SoundTrackManager::SoundTrackManager()
{
}

SoundTrack::SoundTrackManager::~SoundTrackManager()
{
}

void SoundTrack::SoundTrackManager::Init()
{
	music.creditsMusic = LoadMusicStream("../res/music/Game Over! - Harris Cole.mp3");
	music.mainMenuMusic = LoadMusicStream("../res/music/yawgooh - falling apart - Lofi Girl Ambient.mp3");
	music.gameOverMusic = LoadMusicStream("../res/music/JEN - QUIET NIGHTS - soulmate.mp3");
	music.gamePlayMusic = LoadMusicStream("../res/music/JEN - FACADE - soulmate.mp3");
}

void SoundTrack::SoundTrackManager::SetCurrentMusic(MenuOptions gameState)
{
	StopMusic();

	switch (gameState)
	{
	case MenuOptions::MainMenu:

		MainMenuOrganization();
		break;

	case MenuOptions::Playing:

		GameOverOrganization();
		break;

	case MenuOptions::GameOver:

		GamePlayOrganization();
		break;

	case MenuOptions::Rules:

		MainMenuOrganization();
		break;

	case MenuOptions::Credits:

		CreditsOrganization();
		break;

	default:
		break;
	}
}

void SoundTrack::SoundTrackManager::Update()
{
	if (actualMusic != nullptr)
	{
		if (!IsMusicStreamPlaying(*actualMusic))
			PlayMusicStream(*actualMusic);

		UpdateMusicStream(*actualMusic);
	}
}

void SoundTrack::SoundTrackManager::Unload()
{
	UnloadMusicStream(music.creditsMusic);
	UnloadMusicStream(music.mainMenuMusic);
	UnloadMusicStream(music.gameOverMusic);
	UnloadMusicStream(music.gamePlayMusic);
}

void SoundTrack::SoundTrackManager::StopMusic()
{
	if (actualMusic != nullptr && IsMusicStreamPlaying(*actualMusic))
		StopMusicStream(*actualMusic);
}

void SoundTrack::SoundTrackManager::MainMenuOrganization()
{
	actualMusic = &music.mainMenuMusic;

	stopMusic[0] = &music.gamePlayMusic;
	stopMusic[1] = &music.gameOverMusic;
	stopMusic[2] = &music.creditsMusic;
}

void SoundTrack::SoundTrackManager::GamePlayOrganization()
{
	actualMusic = &music.gamePlayMusic;

	stopMusic[0] = &music.mainMenuMusic;
	stopMusic[1] = &music.gameOverMusic;
	stopMusic[2] = &music.creditsMusic;
}

void SoundTrack::SoundTrackManager::GameOverOrganization()
{
	actualMusic = &music.gameOverMusic;

	stopMusic[0] = &music.mainMenuMusic;
	stopMusic[1] = &music.gamePlayMusic;
	stopMusic[2] = &music.creditsMusic;
}

void SoundTrack::SoundTrackManager::CreditsOrganization()
{
	actualMusic = &music.creditsMusic;

	stopMusic[0] = &music.gamePlayMusic;
	stopMusic[1] = &music.gameOverMusic;
	stopMusic[2] = &music.mainMenuMusic;
}

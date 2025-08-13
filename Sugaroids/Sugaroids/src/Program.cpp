#include "Program.h"

#include <ctime>

#include "Gameplay/Gameplay.h"
#include "Buttons.h"

const int Program::Program::screenWidth = 1024;
const int Program::Program::screenHeight = 768;

Program::Program::Program()
{
}

Program::Program::~Program()
{
}

void Program::Program::Init()
{
	CreateWindow();

	InitAssets();

	InitAudioDevice();
	soundTrackManager.Init();

	Loop();

	CloseAudioDevice();
	CloseWindow();
}

void Program::Program::CreateWindow()
{
#pragma warning(disable:4244)
	std::srand(std::time(nullptr));
#pragma warning(default:4244)

	InitWindow(screenWidth, screenHeight, programName.c_str());

	SetTargetFPS(144);

	SetExitKey(0);
}

void Program::Program::InitAssets()
{
	font = LoadFontEx("../res/fonts/rubikBubbles/RubikBubbles-Regular.ttf", static_cast<int>(titlesFontSize), 0, 0);

	soundTrackManager.Init();
	vfxManager.Init();
	textureManager.Init();
}

void Program::Program::UnloadAssets()
{
	soundTrackManager.Unload();
	vfxManager.Unload();
	textureManager.Unload();
}


void Program::Program::SetState(MenuOptions state)
{
	switch (state)
	{
	case MenuOptions::MainMenu:
	case MenuOptions::Playing:

		previousMenu = state;
		gameState = state;

		break;

	default:

		previousMenu = gameState;
		gameState = state;

		break;
	}

	soundTrackManager.SetCurrentMusic(gameState);
}

void Program::Program::Loop()
{
	while (!WindowShouldClose() && gameState != MenuOptions::Exit)
	{
		time = GetTime();

		soundTrackManager.Update();

		switch (gameState)
		{
		case MenuOptions::MainMenu:

			if (IsKeyPressed(KEY_ESCAPE))
				SetState(MenuOptions::WantToExit);
			break;

		case MenuOptions::Playing:

			break;

		case MenuOptions::Rules:
		case MenuOptions::Credits:
			break;

		case MenuOptions::WantToExit:

			if (IsKeyPressed(KEY_ESCAPE))
				gameState = MenuOptions::MainMenu;

			ConfirmExit();

			break;

		default:
			break;
		}


		BeginDrawing();

		ClearBackground(BLACK);

		std::string pointsText = "Points: " + std::to_string(points);
		std::string playerLives = "Lives: " + std::to_string(player.lives);

		DrawTexturePro(
			textureManager.background,
			Rectangle{ 0.0f, 0.0f, static_cast<float>(textureManager.background.width), static_cast<float>(textureManager.background.height) },
			Rectangle{ 0.0f, 0.0f, static_cast<float>(screenWidth), static_cast<float>(screenWidth) },
			Vector2{ 0, 0 },
			0.0f,
			WHITE);

		switch (gameState)
		{
		case MenuOptions::MainMenu:

			if (timmerToCleanBuffer <= 0)
				Scene::DrawMainMenu(gameState, font, textureManager.gamesTitle);
			else
				timmerToCleanBuffer -= 1 * deltaTime;
			break;

		case MenuOptions::Playing:

			if (timmerToCleanBuffer <= 0)
			{
				if (gameOver)
				{
					Scene::DrawGameOver(gameState, font);

					GameManager::ShouldResetMatch(gameState, player, bullets, sugaroids, gameOver, points, sugaroidsSpawnRate, spawnTimer);
				}
				else
				{
					Scene::DrawGamePlay(shader, bullets, sugaroids, player, textureManager.bullets, textureManager.player, textureManager.sugaroid, textureManager.cometkie, textureManager.chip);

					if (pause)
					{
						Scene::DrawPauseMenu(gameState, font, pause);

						if (gameState == MenuOptions::MainMenu)
							GameManager::ResetGame(bullets, sugaroids, player, gameOver, points, sugaroidsSpawnRate, spawnTimer);
					}

					if (player.levelingUp && !allBoostsUnlocked)
					{
						Scene::DrawPowerUpUnlockHud(player.lastPowerUnlock, player.levelingUp, font);
					}

					DrawTextEx(font, pointsText.c_str(), Vector2{ 0,0 }, scoreFontSize, 0, BLACK);
					DrawTextEx(font, playerLives.c_str(), Vector2{ 0, 20 }, scoreFontSize, 0, BLACK);

				}
			}
			else
				timmerToCleanBuffer -= 0.1f * deltaTime;

			break;

		case MenuOptions::Rules:

			Scene::DrawGameRules(gameState, font);
			break;

		case MenuOptions::Credits:

			Scene::DrawCredits(gameState, font);
			break;

		case MenuOptions::WantToExit:

			Scene::DrawConfirmExit(gameState, font, previousMenu);

			break;

		default:
			break;
		}

		EndDrawing();
	}

	UnloadShader(shader);
	UnloadAssets();
}

void Program::Program::ConfirmExit()
{
	const int maxButtons = 2;

	Color outLine = BLACK;

	Vector2 mouse = GetMousePosition();
	Button button[maxButtons];

	float startX, startY;

	startX = (screenWidth - buttonWidth) / 2;
	startY = (screenHeight - (buttonHeight * maxButtons + buttonSpacing * (maxButtons - 1))) / 2;

	button[0].option = MenuOptions::ConfirmExit;
	button[1].option = MenuOptions::CancelExit;

	for (int i = 0; i < maxButtons; i++)
	{
		button[i].rec = { startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight };

		switch (button[i].option)
		{
		case MenuOptions::ConfirmExit:

			button[i].color = RED;
			break;

		case MenuOptions::CancelExit:

			button[i].color = GREEN;
			break;

		default:
			break;
		}
	}

	for (int i = 0; i < maxButtons; i++)
	{
		if (Tools::CheckMouseButtonCollition(mouse, button[i].rec))
		{
			button[i].color = WHITE;

			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			{
				button[i].color = YELLOW;
			}

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				SetState(button[i].option);
		}
	}

	switch (gameState)
	{
	case MenuOptions::ConfirmExit:

		gameState = MenuOptions::Exit;
		break;

	case MenuOptions::CancelExit:

		gameState = previousMenu;
		timmerToCleanBuffer = 0.01f;
		break;

	default:
		break;
	}
}

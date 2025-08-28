#include "Program.h"

#include <ctime>

#include "Gameplay/Gameplay.h"
#include "Menus/MainMenu/MainMenu.h"
#include "Button.h"

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
	font = LoadFontEx("../res/fonts/rubikBubbles/RubikBubbles-Regular.ttf", static_cast<int>(TitleFontSize), 0, 0);

	currentState = new MainMenu(gameState, font, nullptr);

	soundTrackManager.Init();
	vfxManager.Init();
	textureManager.Init();
}

void Program::Program::UnloadAssets()
{
	UnloadFont(font);

	soundTrackManager.Unload();
	vfxManager.Unload();
	textureManager.Unload();

	CloseAudioDevice();
	CloseWindow();
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
		Update();

		Draw();
	}
}

void Program::Program::Update()
{
	time = GetTime();

	mouse = GetMousePosition();

	soundTrackManager.Update();

	if (currentState != nullptr)
		currentState->Update(mouse);

	/*
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
	*/
}

void Program::Program::Draw()
{
	if (currentState != nullptr)
		currentState->Draw();
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

#include "MainMenu.h"

#include "Program.h"

Menus::MainMenu::MainMenu()
{
}

Menus::MainMenu::MainMenu(MenuOptions& gameState, Font& font, Texture2D& gameTitle) : Menu(gameState, font)
{
	this->gameTitle = &gameTitle;
}

Menus::MainMenu::~MainMenu()
{
}

void Menus::MainMenu::Init()
{
	Menu::Init();

	for (int i = 0; i < maxButtons; i++)
	{
		buttons[i].SetOption(static_cast<int>(MenuOptions::Playing));

		if (i == maxButtons - 1)
			buttons[i].SetOption(static_cast<int>(MenuOptions::WantToExit));
	}
}

void Menus::MainMenu::Draw()
{
	if (gameTitle != nullptr)
		DrawTexturePro(
			*gameTitle,
			Rectangle{ 0, 0, static_cast<float>(gameTitle->width), static_cast<float>(gameTitle->height) },  // Source: Texture size
			Rectangle{ static_cast<float>(Program::Program::screenWidth) / 2 - gameTitle->width / 2,  // X Pos
					   static_cast<float>(Program::Program::screenHeight) / 3 - gameTitle->height / 2, // Y Pos
					   static_cast<float>(gameTitle->width),
					   static_cast<float>(gameTitle->height) },
			Vector2{ 0, 0 },  // Offset from center
			0.0f,  // Ratation
			WHITE
		);

	for (Button button : buttons)
		button.Draw();
}

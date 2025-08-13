#include "MainMenu.h"

#include "Buttons.h"
#include "Program.h"

Menus::MainMenu::MainMenu()
{
}

Menus::MainMenu::MainMenu(MenuOptions& gameState, Texture2D& gameTitle)
{
	this->gameState = &gameState;
	this->gameTitle = &gameTitle;
}

Menus::MainMenu::~MainMenu()
{
}

void Menus::MainMenu::Init()
{
	buttons.reserve(maxButtons);

	float startX = (Program::Program::screenWidth - buttonWidth) / 2;
	float startY = Program::Program::screenHeight - (buttonHeight * maxButtons + buttonSpacing * (maxButtons - 1));

	for (vector<Button>::iterator buttonIT = buttons.begin(), int i; buttonIT != buttons.end(); buttonIT++, i++)
	{
		buttonIT->SetRectangle
		(
			Rectangle
			{
				startX,
				startY + i * (buttonHeight + buttonSpacing),
				buttonWidth,
				buttonHeight
			}
		);
	}

	for (int i = 0; i < maxButtons; i++)
	{
		buttons[i].SetOption(static_cast<int>(MenuOptions::Playing));

		if (i == maxButtons - 1)
			buttons[i].SetOption(static_cast<int>(MenuOptions::WantToExit));
	}
}

void Menus::MainMenu::Update(Vector2 mouse)
{
	for (Button button : buttons)
	{
		if (button.CheckIfWasPressed(mouse))
			*gameState = static_cast<MenuOptions>(button.GetOption());
	}
}

void Menus::MainMenu::Draw()
{
	if (gameTitle != nullptr)
		DrawTexturePro(
			*gameTitle,
			Rectangle{ 0, 0, static_cast<float>(gameTitle->width), static_cast<float>(gameTitle->height) },  // Fuente: toda la imagen original
			Rectangle{ static_cast<float>(Program::Program::screenWidth) / 2 - gameTitle->width / 2,  // Posición X centrada
					   static_cast<float>(Program::Program::screenHeight) / 3 - gameTitle->height / 2,  // Posición Y centrada
					   static_cast<float>(gameTitle->width),  // Ancho del título
					   static_cast<float>(gameTitle->height) },  // Altura del título
			Vector2{ 0, 0 },  // Offset del centro
			0.0f,  // Sin rotación
			WHITE  // Sin tintes de color
		);
}

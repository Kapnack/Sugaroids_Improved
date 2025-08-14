#include "Menu.h"

#include "Program.h"

const float Menu::buttonWidth = 200.0f;
const float Menu::buttonHeight = 60.0f;
const float Menu::buttonSpacing = 20.0f;

const float Menu::titlesFontSize = 100;
const float Menu::textFontSize = 40;
const float Menu::scoreFontSize = 30;

Menu::Menu()
{
}

Menu::Menu(MenuOptions& gameState, Font& font)
{
	this->gameState = &gameState;
	this->font = &font;
}

Menu::~Menu()
{
}

void Menu::Init()
{
	buttons.reserve(buttonsAmount);

	float startX = (Program::Program::screenWidth - buttonWidth) / 2;
	float startY = Program::Program::screenHeight - (buttonHeight * buttonsAmount + buttonSpacing * (buttonsAmount - 1));

	for (std::vector<Button>::iterator buttonIT = buttons.begin(), int i = 0; buttonIT != buttons.end(); ++buttonIT, ++i)
		buttonIT->SetRectangle(Rectangle{ startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight });
}

void Menu::Update(Vector2 mouse)
{
	for (Button button : buttons)
	{
		if (button.CheckIfWasPressed(mouse))
			*gameState = static_cast<MenuOptions>(button.GetOption());
	}
}

void Menu::Unload()
{
	buttons.clear();
}

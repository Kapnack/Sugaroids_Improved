#include "Pause.h"

#include "Program.h"

Pause::Pause()
{
}

Pause::Pause(MenuOptions& gameState, Font& font) : Menu(gameState, font)
{
	titleText = "Pause";
}

Pause::~Pause()
{
}

void Pause::Init()
{
	Menu::Init();

	std::vector<Button>::iterator buttonIT = buttons.begin();

	buttonIT->SetOption(static_cast<int>(MenuOptions::Resume)); buttonIT++;
	buttonIT->SetOption(static_cast<int>(MenuOptions::MainMenu)); buttonIT++;
	buttonIT->SetOption(static_cast<int>(MenuOptions::WantToExit)); buttonIT++;

	titlePos =
	{
		static_cast<float>(Program::Program::screenWidth) / 2 - MeasureTextEx(*font, titleText.c_str(), titlesFontSize, 2).x / 2,
		static_cast<float>(Program::Program::screenHeight) / 5
	};
}

void Pause::Draw()
{
	DrawRectangle(0, 0, Program::Program::screenWidth, Program::Program::screenHeight, semiTransparentBlack);

	if (font != nullptr)
		DrawTextEx(*font, titleText.c_str(), titlePos, titlesFontSize, 2, pastelPurple);
	else
		DrawText(titleText.c_str(), titlePos.x, titlePos.y, titlesFontSize, pastelPurple);

	for (Button button : buttons)
		button.Draw();

}

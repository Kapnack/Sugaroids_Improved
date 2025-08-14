#pragma once

#include <raylib.h>

#include <Vector>

#include "ProgramState.h"
#include "Program.h"
#include "Button.h"

class Menu : public ProgramState
{
protected:

	static const float buttonWidth;
	static const float buttonHeight;
	static const float buttonSpacing;

	static const float titlesFontSize;
	static const float textFontSize;
	static const float scoreFontSize;

	int buttonsAmount = 0;

	string titleText = "";

	MenuOptions* gameState = nullptr;

	Font* font;

	std::vector<Button> buttons;

public:

	Menu();
	Menu(MenuOptions& gameState, Font& font);
	virtual ~Menu();

	virtual void Init() override;

	virtual void Update(Vector2 mouse) override;

	void Unload() override;
};


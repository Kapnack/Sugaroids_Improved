#pragma once

#include <raylib.h>

#include <Vector>

#include "ProgramState.h"
#include "Buttons.h"

class Menu : public ProgramState
{
protected:

	static const float buttonWidth;
	static const float buttonHeight;
	static const float buttonSpacing;

	static const float titlesFontSize;
	static const float textFontSize;
	static const float scoreFontSize;

	std::vector<Button> buttons;

public:

	Menu();
	virtual ~Menu();
};


#pragma once

#include "Menus/Menu.h"

class Pause : public Menu
{
private:

	Color pastelPurple = { 214, 196, 224, 255 };
	Color semiTransparentBlack = { 0, 0, 0, 150 };

	Vector2 titlePos = {};

public:

	Pause();
	Pause(MenuOptions& gameState, Font& font);
	~Pause() override;

	virtual void Init() override;
	void Draw() override;
};


#pragma once

#include "Menus/Menu.h"

namespace Menus
{
	class MainMenu : public Menu
	{
	private:

		Texture2D* gameTitle = nullptr;

		static const int maxButtons = 5;

	public:

		MainMenu();
		MainMenu(MenuOptions& gameState, Font& font, Texture2D& gameTitle);
		~MainMenu() override;

		void Init() override;

		void Draw() override;
	};
}


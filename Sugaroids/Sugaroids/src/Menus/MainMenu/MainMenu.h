#pragma once

#include "Menus/Menu.h"

namespace Menus
{
	class MainMenu : public Menu
	{
	private:

		MenuOptions* gameState = nullptr;

		Texture2D* gameTitle = nullptr;

		static const int maxButtons = 5;

	public:

		MainMenu();
		MainMenu(MenuOptions& gameState, Texture2D& gameTitle);
		~MainMenu() override;

		void Init() override;

		void Update(Vector2 mouse) override;

		void Draw() override;
	};
}


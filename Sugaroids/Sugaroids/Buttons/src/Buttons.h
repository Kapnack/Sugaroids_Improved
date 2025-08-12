#pragma once

#include <raylib.h>

#include <string>

using namespace std;

class Buttons
{
public:

	Buttons();

	Buttons(Rectangle rect, int action, Font font, string text, float fontSize, Color color, Color outLineColor);

	~Buttons();

	int CheckIfPressed(Vector2 mouse);

	void Draw();

	void SetFont(Font font);

	void SetTextSize(float TextSize);

	void SetOption(int action);

	void SetPos(Vector2 pos);

	void SetSize(Vector2 size);

	void SetRectangle(Rectangle rect);

	void SetColorInside(Color color);

	void SetOutLineColor(Color color);

	void SetText(string text);

	void SetLetterSpacing(float letterSpacing);

private:

	bool CheckMouseButtonCollition(Vector2 mouse);

	Rectangle rect = { 0,0,0,0 };

	int action = 0;

	Font font = GetFontDefault();

	string text = "";

	float fontSize = 1.0f;

	float letterSpacing = 1;

	Color actualColor = { 255, 182, 193, 255 };
	Color setColor = WHITE;

	Color actualOutLineColor = BLACK;
	Color setOutLineColor = BLACK;
};
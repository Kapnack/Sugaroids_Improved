#pragma once

#include <raylib.h>

#include <string>

using namespace std;

class Button
{
public:

	Button();

	Button(Rectangle rect, int action, Font font, string text, float fontSize, Color color, Color outLineColor);

	~Button();

	bool CheckIfWasPressed(Vector2 mouse);

	void Draw();

	void SetFont(Font font);

	void SetTextSize(float TextSize);

	void SetOption(int action);
	int GetOption();

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

	int option = 0;

	Font font = GetFontDefault();

	string text = "";

	float fontSize = 1.0f;

	float letterSpacing = 1;

	Color actualColor = { 255, 182, 193, 255 };
	Color settedColor = WHITE;

	Color actualOutLineColor = BLACK;
	Color setOutLineColor = BLACK;
};
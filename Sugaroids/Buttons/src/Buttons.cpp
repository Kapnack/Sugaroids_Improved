
#include "Buttons.h"

Button::Button()
{
}

Button::Button(Rectangle rect, int action, Font font, string text, float fontSize, Color color, Color outLineColor)
{
	this->rect = rect;
	this->option = action;
	this->font = font;
	this->text = text;
	this->fontSize = fontSize;

	actualColor = color;
	actualOutLineColor = outLineColor;

	settedColor = color;
	setOutLineColor = outLineColor;
}

Button::~Button()
{
}

bool Button::CheckMouseButtonCollition(Vector2 mouse)
{
	// is the point inside the rectangle's bounds?
	if (mouse.x >= rect.x &&        // right of the left edge AND
		mouse.x <= rect.x + rect.width &&   // left of the right edge AND
		mouse.y >= rect.y &&        // below the top AND
		mouse.y <= rect.y + rect.height)
	{   // above the bottom

		return true;
	}

	return false;
}

bool Button::CheckIfWasPressed(Vector2 mouse)
{
	if (CheckMouseButtonCollition(mouse))
	{
		actualColor = WHITE;

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			actualColor = YELLOW;

			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
				return true;
		}
	}

	if (!CheckMouseButtonCollition(mouse))
		actualColor = settedColor;

	return false;
}

void Button::Draw()
{
	DrawRectangleRec(rect, actualColor);
	DrawRectangleLinesEx(rect, 2, actualOutLineColor);

	Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, letterSpacing);

	Vector2 textPosition =
	{
		rect.x + (rect.width - textSize.x) / 2,
		rect.y + (rect.height - textSize.y) / 2
	};

	DrawTextPro(font,
		text.c_str(),
		textPosition,
		Vector2{ 0,0 },
		0,
		fontSize,
		0,
		BLACK);
}

void Button::SetFont(Font font)
{
	this->font = font;
}

void Button::SetTextSize(float TextSize)
{
	fontSize = TextSize;
}

void Button::SetOption(int option)
{
	this->option = option;
}

int Button::GetOption()
{
	return option;
}

void Button::SetPos(Vector2 pos)
{
	rect.x = pos.x;
	rect.y = pos.y;
}

void Button::SetSize(Vector2 size)
{
	rect.width = size.x;
	rect.height = size.y;
}

void Button::SetRectangle(Rectangle rect)
{
	this->rect = rect;
}

void Button::SetColorInside(Color color)
{
	this->actualColor = color;
	this->settedColor = color;
}

void Button::SetOutLineColor(Color color)
{
	this->actualOutLineColor = color;
	this->setOutLineColor = color;
}

void Button::SetText(string text)
{
	this->text = text;
}

void Button::SetLetterSpacing(float letterSpacing)
{
	this->letterSpacing = letterSpacing;
}

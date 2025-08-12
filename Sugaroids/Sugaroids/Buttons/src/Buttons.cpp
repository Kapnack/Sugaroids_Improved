
#include "Buttons.h"

Buttons::Buttons()
{
}

Buttons::Buttons(Rectangle rect, int action, Font font, string text, float fontSize, Color color, Color outLineColor)
{
	this->rect = rect;
	this->action = action;
	this->font = font;
	this->text = text;
	this->fontSize = fontSize;

	actualColor = color;
	actualOutLineColor = outLineColor;

	setColor = color;
	setOutLineColor = outLineColor;
}

Buttons::~Buttons()
{
}

bool Buttons::CheckMouseButtonCollition(Vector2 mouse)
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

int Buttons::CheckIfPressed(Vector2 mouse)
{
	if (CheckMouseButtonCollition(mouse))
	{
		actualColor = WHITE;

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			actualColor = YELLOW;
		}

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			return action;
	}

	if (!CheckMouseButtonCollition(mouse))
		actualColor = setColor;

	return 0;
}

void Buttons::Draw()
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

void Buttons::SetFont(Font font)
{
	this->font = font;
}

void Buttons::SetTextSize(float TextSize)
{
	fontSize = TextSize;
}

void Buttons::SetOption(int action)
{
	this->action = action;
}

void Buttons::SetPos(Vector2 pos)
{
	rect.x = pos.x;
	rect.y = pos.y;
}

void Buttons::SetSize(Vector2 size)
{
	rect.width = size.x;
	rect.height = size.y;
}

void Buttons::SetRectangle(Rectangle rect)
{
	this->rect = rect;
}

void Buttons::SetColorInside(Color color)
{
	this->actualColor = color;
	this->setColor = color;
}

void Buttons::SetOutLineColor(Color color)
{
	this->actualOutLineColor = color;
	this->setOutLineColor = color;
}

void Buttons::SetText(string text)
{
	this->text = text;
}

void Buttons::SetLetterSpacing(float letterSpacing)
{
	this->letterSpacing = letterSpacing;
}

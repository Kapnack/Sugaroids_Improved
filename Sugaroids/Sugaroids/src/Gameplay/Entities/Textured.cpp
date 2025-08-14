#include "Textured.h"

Textured::Textured()
{
}

Textured::Textured(Vector2 position, float radius, float angle = 0.0f) : Physics(position, radius, angle)
{
}

Textured::~Textured()
{
}

void Textured::SetTexure(Texture& Texture)
{
	this->texture = texture;
}

void Textured::Draw()
{
	if (texture != nullptr)
		DrawTexturePro
		(
			*texture,
			Rectangle{ 0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height) },  // Fuente (imagen completa)
			Rectangle{ position.x, position.y, size, size },  // Destino (posición y tamaño)
			Vector2{ radius, radius },  // Offset del centro
			angle,
			WHITE
		);
}
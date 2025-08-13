#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(Vector2 position, float angle)
{
	this->position = position;
	this->angle = angle;
}

Entity::~Entity()
{
}

void Entity::SetPosition(Vector2 position)
{
	this->position = position;
}

void Entity::SetAngle(float angle)
{
	this->angle = angle;
}

void Entity::SetSize(float size)
{
	this->size = size;
}

#pragma once

#include "../Bullet.h"

namespace Bullet
{
	class Missile : public Bullet
	{
	public:

		Missile();
		Missile(Vector2 pos, float angle = 0.0f, Sugaroids::Sugaroid* target = nullptr);
		~Missile() override;

		void Movement(float deltaTime = 1.0f) override;

	private:

		Sugaroids::Sugaroid* target = nullptr;
	};
}


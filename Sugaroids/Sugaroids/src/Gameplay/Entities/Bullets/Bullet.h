#pragma once

#include <raylib.h>
#include <list>

#include "Gameplay/Entities/Textured.h"
#include "Gameplay/Entities/Sugaroids/sugaroid.h"
#include "Gameplay/Entities/Player/powerUps.h"

namespace Bullet
{
	class Bullet : public Textured
	{
	protected:

		bool toDestroy = false;

	public:

		Bullet();
		Bullet(Vector2 position, float radius, float angle = 0.0f);
		virtual ~Bullet() override;

		void SetSizeMultiplier(float scalar);
		void SetSpeedMultiplier(float scalar);
	};
}
#include <list>
#include "bullets.hpp"
#include "platform.hpp"
#include <corecrt_math.h>

namespace core {
	void Bullet::animate(float delta_time)
	{
		const float scale = PI * 3;
		this->position = { this->position.x + scale * delta_time * (float)sin(direction), this->position.y + scale * delta_time * (float)cos(direction),this->position.z };
		
	}
	Bullet::Bullet(std::int32_t sprite_index, float direction, Vec3 position)
	{
		this->sprite_index = sprite_index;
		this->direction = direction;
		this->position = position;
	};


	void Bullet::render(core::Renderer* renderer, core::Sprite_Index tiles_sprite_atlas)
	{
		renderer->draw_sprite(position, size, direction, tiles_sprite_atlas, sprite_index);

	}

	
}

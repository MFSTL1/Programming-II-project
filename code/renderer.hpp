#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <cstddef>
#include <cstdint>
#include "math.hpp"

namespace core {
	static inline constexpr std::uint32_t Background_Tile_Count_X = 16;
	static inline constexpr std::uint32_t Background_Tile_Count_Y = 12;

	struct Vertex {
		Vec3 position;
		Vec2 tex_coords;
	};

	struct Sprite_Index {
		std::size_t index;
		std::uint32_t generation;
	};

	class Platform;
	class Renderer {
		void destroy() noexcept;
		void adjust_viewport();
		[[nodiscard]] Sprite_Index insert_sprite(unsigned int texture_id,unsigned int uniform_buffer_id,std::uint32_t array_layers);
		explicit Renderer(Platform* _platform);
	public:
		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		~Renderer();
		void begin(float r,float g,float b);
		void end();
		void draw_sprite(Vec3 position,Vec2 size,float rotation,const Sprite_Index& sprite_index,std::uint32_t tile_index = 0);
		void draw_sprite_colored(Vec3 position,Vec2 size,float rotation,Vec3 color,const Sprite_Index& sprite_index,std::uint32_t tile_index = 0);
		void draw_text(Vec3 position,Vec2 char_size,Vec3 color,const char* text);

		//Texture are freed the moment rendering engine is destroyed.
		[[nodiscard]] Sprite_Index sprite(const char* file_path);
		[[nodiscard]] Sprite_Index sprite_atlas(const char* file_path,std::uint32_t tile_dimension);
	private:
		Platform* platform;
		/*	An object of type 'Renderer_Internal_Data' is placement-newed inside this array internally.
			This is to avoid having to include all of the headers that would be required to make this work. */
		alignas(std::max_align_t) unsigned char data_buffer[128];
		friend class Platform;
	};
}

#endif

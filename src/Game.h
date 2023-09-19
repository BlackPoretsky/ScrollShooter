#pragma once

#include <godot_cpp/classes/node2d.hpp>

namespace godot
{
	class Game : public Node2D
	{
		GDCLASS(Game, Node2D)

	protected:
		static void _bind_methods();

	public:
		Game();
		~Game();

		void CheckInput();
		void PlayerShot(Variant LaserContainer, Variant LaserScene, Vector2 Location);
	};
}



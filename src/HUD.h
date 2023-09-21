#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/control.hpp"

namespace godot 
{
	class HUD : public  Control
	{
		GDCLASS(HUD, Control)

	protected:
		static void _bind_methods();

	public:
		HUD();
		~HUD();

		void SetScore(String score);
	};
}



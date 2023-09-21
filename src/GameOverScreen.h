#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/control.hpp"

namespace godot
{
	class GameOverScreen : public Control
	{
		GDCLASS(GameOverScreen, Control)

	protected:
		static void _bind_methods();

	public:
		GameOverScreen();
		~GameOverScreen();

		void RestartGame();
		void SetScore(String score);
		void SetHighScore(String highScore);
	};
}



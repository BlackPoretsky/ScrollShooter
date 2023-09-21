#pragma once

#include <godot_cpp/classes/node2d.hpp>

namespace godot
{
	class Game : public Node2D
	{
		GDCLASS(Game, Node2D)

	protected:
		static void _bind_methods();
		int Score = 0;
		int HighScore;

	public:
		Game();
		~Game();

		void CheckInput();
		void PlayerShot(Variant laserScene, Vector2 location);
		void EnemySpawn(Variant enemy);
		void SaveGame();
		void LoadSaveGame();

		void SetScore(int score) { Score = score; }
		int GetScore() { return Score; }
		void SetHighScore(int highScore) { HighScore = highScore; }
		int GetHighScore() { return HighScore; }
	};
}



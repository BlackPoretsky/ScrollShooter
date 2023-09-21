#include "GameOverScreen.h"

#include "../godot-cpp/gen/include/godot_cpp/classes/button.hpp"
#include "../godot-cpp/gen/include/godot_cpp/classes/scene_tree.hpp"
#include "../godot-cpp/gen/include/godot_cpp/classes/label.hpp"

void godot::GameOverScreen::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("SetScore", "score"), &GameOverScreen::SetScore);
	ClassDB::bind_method(D_METHOD("SetHighScore", "highScore"), &GameOverScreen::SetHighScore);
	ClassDB::bind_method(D_METHOD("RestartGame"), &GameOverScreen::RestartGame);
}

godot::GameOverScreen::GameOverScreen()
{
}

godot::GameOverScreen::~GameOverScreen()
{
}

void godot::GameOverScreen::RestartGame()
{
	Button* RestartButton = get_node<Button>("Panel/Restart");
	if (RestartButton->is_pressed())
	{
		get_tree()->reload_current_scene();
	}
}

void godot::GameOverScreen::SetScore(String score)
{
	Label* label = get_node<Label>("Panel/Score");
	label->set_text("SCORE: " + score);
}

void godot::GameOverScreen::SetHighScore(String highScore)
{
	Label* label = get_node<Label>("Panel/HiScore");
	label->set_text("HI-SCORE: " + highScore);
}

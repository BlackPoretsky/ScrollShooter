#include "Game.h"
#include <random>
#include <fstream>

#include <godot_cpp/core/class_db.hpp>
#include "../godot-cpp/gen/include/godot_cpp/classes/input.hpp"
#include "../godot-cpp/gen/include/godot_cpp/classes/scene_tree.hpp"
#include "../godot-cpp/gen/include/godot_cpp/variant/utility_functions.hpp"

#include "Laser.h"

void godot::Game::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("CheckInput"), &Game::CheckInput);
	ClassDB::bind_method(D_METHOD("PlayerShot"), &Game::PlayerShot);
	ClassDB::bind_method(D_METHOD("EnemySpawn"), &Game::EnemySpawn);
	ClassDB::bind_method(D_METHOD("SaveGame"), &Game::SaveGame);
	ClassDB::bind_method(D_METHOD("LoadSaveGame"), &Game::LoadSaveGame);

	ClassDB::bind_method(D_METHOD("SetScore"), &Game::SetScore);
	ClassDB::bind_method(D_METHOD("GetScore"), &Game::GetScore);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Score"), "SetScore", "GetScore");

	ClassDB::bind_method(D_METHOD("SetHighScore"), &Game::SetHighScore);
	ClassDB::bind_method(D_METHOD("GetHighScore"), &Game::GetHighScore);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "HighScore"), "SetHighScore", "GetHighScore");
}

godot::Game::Game()
{
	srand(time(0));
}

godot::Game::~Game()
{
}

void godot::Game::CheckInput()
{
	if (Input::get_singleton()->is_action_pressed("quit"))
	{
		SaveGame();
		get_tree()->quit();
	}
	else if (Input::get_singleton()->is_action_pressed("reset"))
	{
		SaveGame();
		get_tree()->reload_current_scene();
	}
}

void godot::Game::PlayerShot(Variant laserScene, Vector2 location)
{
	Node2D* LaserContainer = get_node<Node2D>("LaserContainer");
	Area2D* LaserScene = cast_to<Area2D>(laserScene);
	LaserScene->set_global_position(location);
	LaserContainer->add_child(LaserScene);
}

void godot::Game::EnemySpawn(Variant enemy)
{
	Node* EnemyContainer = get_node<Node>("EnemyContainer");
	Area2D* Enemy = cast_to<Area2D>(enemy);
	Enemy->set_global_position(Vector2(40 + ( rand() % 461), 20));
	EnemyContainer->add_child(Enemy);
}

void godot::Game::SaveGame()
{
	std::ofstream Save("save.txt", std::ios::out);
	if (Save.is_open() && !Save.eof())
	{
		Save << HighScore;
		Save.close();
	}
	else
		UtilityFunctions::print("Failed to open save file!");
}

void godot::Game::LoadSaveGame()
{
	std::ifstream Save("save.txt", std::ios::in);
	if (Save.is_open() && !Save.eof())
	{
		Save >> HighScore;
		Save.close();
	}
	else
	{
		SaveGame();
		HighScore = 0;
	}
}

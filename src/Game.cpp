#include "Game.h"

#include <godot_cpp/core/class_db.hpp>
#include "../godot-cpp/gen/include/godot_cpp/classes/input.hpp"
#include "../godot-cpp/gen/include/godot_cpp/classes/scene_tree.hpp"

#include "Laser.h"

void godot::Game::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("CheckInput"), &Game::CheckInput);
	ClassDB::bind_method(D_METHOD("PlayerShot"), &Game::PlayerShot);
}

godot::Game::Game()
{
}

godot::Game::~Game()
{
}

void godot::Game::CheckInput()
{
	if (Input::get_singleton()->is_action_pressed("quit"))
	{
		get_tree()->quit();
	}
	else if (Input::get_singleton()->is_action_pressed("reset"))
	{
		get_tree()->reload_current_scene();
	}
}

void godot::Game::PlayerShot(Variant LaserContainer, Variant LaserScene, Vector2 Location)
{
	Node2D* Container = get_node<Node2D>("LaserContainer");
	Area2D* Laser = cast_to<Area2D>(LaserScene);
	Laser->set_global_position(Location);
	Container->add_child(Laser);
}

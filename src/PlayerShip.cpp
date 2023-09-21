#include "PlayerShip.h"
#include "../godot-cpp/gen/include/godot_cpp/classes/input.hpp" 

void godot::PlayerShip::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("SetVelocity"), &PlayerShip::SetVelocity);
	ClassDB::bind_method(D_METHOD("GetVelocity"), &PlayerShip::GetVelocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Velocity"), "SetVelocity", "GetVelocity");

	ClassDB::bind_method(D_METHOD("Move", "delta"), &PlayerShip::Move);
	ClassDB::bind_method(D_METHOD("Shoot", "delta"), &PlayerShip::Shoot);
	ClassDB::bind_method(D_METHOD("Die"), &PlayerShip::Die);
}

godot::PlayerShip::PlayerShip()
{
}

godot::PlayerShip::~PlayerShip()
{
}

void godot::PlayerShip::Move(double delta)
{
	auto Direction = Vector2(Input::get_singleton()->get_axis("MoveLeft", "MoveRight"), Input::get_singleton()->get_axis("MoveUp", "MoveDown"));
	Vector2 Location = get_global_position();
	Location = Location + (Direction.normalized() * Velocity * delta);
	Location.x = CLAMP(Location.x, 40, 500);
	Location.y = CLAMP(Location.y, 40, 920);
	set_position(Location);
}

void godot::PlayerShip::Shoot(Variant lazerScene, Variant muzzel)
{ 
	if (Input::get_singleton()->is_action_just_pressed("shoot"))
	{
			emit_signal("laser_shot", lazerScene, muzzel);
	}	
}

void godot::PlayerShip::Die()
{
	emit_signal("killed");
	queue_free();
}

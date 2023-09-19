#include "Laser.h"

void godot::Laser::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("SetVelocity"), &Laser::SetVelocity);
	ClassDB::bind_method(D_METHOD("GetVelocity"), &Laser::GetVelocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Velocity"), "SetVelocity", "GetVelocity");

	ClassDB::bind_method(D_METHOD("SetDamage"), &Laser::SetDamage);
	ClassDB::bind_method(D_METHOD("GetDamage"), &Laser::GetDamage);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Damage"), "SetDamage", "GetDamage");

	ClassDB::bind_method(D_METHOD("Begin", "delta"), &Laser::Begin);
}

godot::Laser::Laser()
{
}

godot::Laser::~Laser()
{
}

void godot::Laser::Begin(double delta)
{
	Vector2 Location = get_global_position();
	Location.y += -Velocity * delta;
	set_position(Location);
}

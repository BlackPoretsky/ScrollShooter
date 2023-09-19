#include "Enemy.h"

void godot::Enemy::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("SetVelocity"), &Enemy::SetVelocity);
	ClassDB::bind_method(D_METHOD("GetVelocity"), &Enemy::GetVelocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Velocity"), "SetVelocity", "GetVelocity");

	ClassDB::bind_method(D_METHOD("SetHP"), &Enemy::SetHP);
	ClassDB::bind_method(D_METHOD("GetHP"), &Enemy::GetHP);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "HP"), "SetHP", "GetHP");
	
	ClassDB::bind_method(D_METHOD("Begin", "delta"), &Enemy::Begin);
	ClassDB::bind_method(D_METHOD("Die"), &Enemy::Die);
	ClassDB::bind_method(D_METHOD("TakeDamage", "Damage"), &Enemy::TakeDamage);
}

godot::Enemy::Enemy()
{
}

godot::Enemy::~Enemy()
{
}

void godot::Enemy::Begin(double delta)
{
	Vector2 Location = get_global_position();
	Location.y += static_cast<double>(Velocity) * delta;
	set_position(Location);
}

void godot::Enemy::TakeDamage(int Damage)
{
	HP -= Damage;
	if (HP <= 0)
		Die();
}

void godot::Enemy::Die()
{
	queue_free();
}

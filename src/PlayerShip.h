#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/character_body2d.hpp"

namespace godot 
{
	class PlayerShip : public CharacterBody2D
	{
		GDCLASS(PlayerShip, CharacterBody2D)

	private:
		double Velocity;

	protected:
		static void _bind_methods();

	public:
		PlayerShip();
		~PlayerShip();

		void Move(double delta);
		void Shoot(Variant lazerScene, Variant muzzel);
		void Die();

		void SetVelocity(double velocity) { Velocity = velocity; }
		double GetVelocity() { return Velocity; }
	};
}



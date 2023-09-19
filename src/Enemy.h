#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/area2d.hpp"

namespace godot
{
	class Enemy : public Area2D
	{
		GDCLASS(Enemy, Area2D)

	private:
		float Velocity = 300;
		int HP = 1;

	protected:
		static void _bind_methods();

	public:
		Enemy();
		~Enemy();

		void Begin(double delta);
		void TakeDamage(int Damage);
		void Die();

		void SetHP(int hp) { HP = hp; }
		int GetHP() { return HP; }

		void SetVelocity(float velocity) { Velocity = velocity; }
		double GetVelocity() { return Velocity; }
	};
}


#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/area2d.hpp"

namespace godot
{
	class Enemy : public Area2D
	{
		GDCLASS(Enemy, Area2D)

	private:
		float Velocity;
		int HP;
		int Points;

	protected:
		static void _bind_methods();

	public:
		Enemy();
		~Enemy();

		void Begin(double delta);
		void TakeDamage(int damage);
		void Die();

		void SetPoints(int points) { Points = points; }
		void SetVelocity(float velocity) { Velocity = velocity; }
		void SetHP(int hp) { HP = hp; }

		int GetHP() { return HP; }
		int GetPoints() { return Points; }
		double GetVelocity() { return Velocity; }
	};
}


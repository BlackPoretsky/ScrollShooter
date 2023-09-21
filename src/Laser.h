#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/area2d.hpp"

namespace godot
{
	class Laser : public Area2D
	{
		GDCLASS(Laser, Area2D)

	private:
		double Velocity;
		int Damage;

	protected:
		static void _bind_methods();

	public:
		Laser();
		~Laser();

		void Begin(double delta);

		void SetVelocity(double velocity) { Velocity = velocity; }
		void SetDamage(int damage) { Damage = damage; }

		double GetVelocity() { return Velocity; }
		double GetDamage() { return Damage; }
	};

}


#pragma once

#include "../godot-cpp/gen/include/godot_cpp/classes/area2d.hpp"

namespace godot
{
	class Laser : public Area2D
	{
		GDCLASS(Laser, Area2D)

	private:
		double Velocity = 600;
		int Damage = 1;

	protected:
		static void _bind_methods();

	public:
		Laser();
		~Laser();

		void Begin(double delta);

		void SetDamage(int damage) { Damage = damage; }
		double GetDamage() { return Damage; }

		void SetVelocity(double velocity) { Velocity = velocity; }
		double GetVelocity() { return Velocity; }
	};

}


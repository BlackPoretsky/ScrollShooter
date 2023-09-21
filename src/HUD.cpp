#include "HUD.h"

#include "../godot-cpp/gen/include/godot_cpp/classes/label.hpp"

void godot::HUD::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("SetScore", "score"), &HUD::SetScore);
}

godot::HUD::HUD()
{
}

godot::HUD::~HUD()
{
}

void godot::HUD::SetScore(String score)
{
	Label* label = get_node<Label>("Score");
	label->set_text("SCORE: " + score);
}

extends PlayerShip

signal laser_shot(laser_scene, location)

@onready var muzzel = $Muzzel

var laser_scene = preload("res://Scenes/laser.tscn")

var delay = false

func _process(delta):
	if !delay:
		delay = true
		Shoot(laser_scene, muzzel.global_position)
		await get_tree().create_timer(0.25).timeout
		delay = false

func _physics_process(delta):
	Move(delta)

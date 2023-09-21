extends PlayerShip

signal laser_shot(laser_scene, location)
signal killed()

@onready var muzzel = $Muzzel

var laser_scene = preload("res://Scenes/laser.tscn")

func _process(delta):
	Shoot(laser_scene, muzzel.global_position)

func _physics_process(delta):
	Move(delta)

extends Game

var player = null

@export var enemy_scenes: Array[PackedScene] = []

@onready var laser_container = $LaserContainer
@onready var timer = $EnemySpawnerTimer
@onready var enemy_container = $EnemyContainer

func _ready():
	player = get_tree().get_first_node_in_group("player")
	player.laser_shot.connect(_on_player_laser_shot)

func _process(delta):
	CheckInput()

func _on_player_laser_shot(laser_scene, location):
	PlayerShot(laser_container, laser_scene.instantiate(), location)


func _on_enemy_spawner_timer_timeout():
	var e = enemy_scenes.pick_random().instantiate()
	e.global_position = Vector2(randf_range(40, 500), 20)
	enemy_container.add_child(e)

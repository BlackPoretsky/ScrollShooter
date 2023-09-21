extends Game

@export var enemy_scenes: Array[PackedScene] = []

@onready var laser_container = $LaserContainer
@onready var timer = $EnemySpawnerTimer
@onready var enemy_container = $EnemyContainer
@onready var hud = $UILayer/HUD
@onready var gos = $UILayer/GameOverScreen
@onready var pb = $ParallaxBackground

var player = null
var scroll_speed = 100

func _ready():
	LoadSaveGame()
	player = get_tree().get_first_node_in_group("player")
	player.laser_shot.connect(_on_player_laser_shot)
	player.killed.connect(_on_player_killed)

func _process(delta):
	CheckInput()
	if timer.wait_time > 0.5:
		timer.wait_time -= delta*0.005 
	pb.scroll_offset.y += delta*scroll_speed
	if pb.scroll_offset.y > 960:
		pb.scroll_offset.y = 0

func _on_player_laser_shot(laser_scene, location):
	PlayerShot(laser_scene.instantiate(), location)

func _on_enemy_spawner_timer_timeout():
	var enemy = enemy_scenes.pick_random().instantiate()
	enemy.killed.connect(_on_enemy_killed)
	EnemySpawn(enemy)

func _on_enemy_killed(points):
	Score += points
	if Score > HighScore:
		HighScore = Score
	hud.SetScore(str(Score))

func _on_player_killed():
	SaveGame()
	gos.SetScore(str(Score))
	gos.SetHighScore(str(HighScore))
	await get_tree().create_timer(0.5).timeout
	gos.visible = true

extends Enemy

signal  killed(points)

func _physics_process(delta):
	Begin(delta)

func _on_body_entered(body):
	if body is PlayerShip:
		body.Die()
		Die()
	
func _on_visible_on_screen_enabler_2d_screen_exited():
	Die()

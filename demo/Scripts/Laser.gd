extends Laser

func _physics_process(delta):
	Begin(delta)

func _on_visible_on_screen_enabler_2d_screen_exited():
	queue_free()


func _on_area_entered(area):
	if area is Enemy:
		area.TakeDamage(Damage)
		queue_free()
	

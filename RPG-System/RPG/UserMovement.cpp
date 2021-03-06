#include "UserMovement.h"
#include "Tile.h"
#include "LocalMap.h"
#include "GameObject.h"
#include "Utility.h"

// handle events. set direction from events
void UserMovement::handleEvents(const Control& controls)
{
	if (controls.isPressed(RIGHT))
		_direction.x = 1;
	else if (controls.isPressed(LEFT))
		_direction.x = -1;
	else _direction.x = 0;

	if (controls.isPressed(UP))
		_direction.y = -1;
	else if (controls.isPressed(DOWN))
		_direction.y = 1;
	else _direction.y = 0;

	// toggle run mode
	if (controls.isPressed(B))
		_run = true;
	else _run = false;
}

bool UserMovement::Update(LocalMap& localmap, GameObject& my_obj, Graphics& my_graphics, float elapsedTime)
{
	// set _direction and speed speed
	float scalar = 1.f;
	if (_run)
		scalar*=2.f;
	
	_speed = _curr_speed * scalar;

	// move
	return Movement::Update(localmap, my_obj, my_graphics, elapsedTime);
}
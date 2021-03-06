#include "RandMovement.h"
#include "Tile.h"
#include "LocalMap.h"
#include "GameObject.h"
#include "Utility.h"


void RandMovement::handleEvents(const Control& controls)
{

}
// set new direction and move
bool RandMovement::Update(LocalMap& localmap, GameObject& my_obj, Graphics& my_graphics, float elapsedTime)
{
	// sometimes you move, sometimes you rest.
	_next_move_timer -= elapsedTime;
	_moving_duration_timer -= elapsedTime;

	// randomize next move
	if (_next_move_timer <= 0)
	{
		_curr_dir.x = float(rand() % 3 -1);
		_curr_dir.y = float(rand() % 3 -1);
		_next_move_timer = _time_between_moves;
		_moving_duration_timer = 1.f;
	}

	if (_moving_duration_timer > 0)
		return false;

	_direction = _curr_dir;

	return Movement::Update(localmap, my_obj, my_graphics, elapsedTime);
}
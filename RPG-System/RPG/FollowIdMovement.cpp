#include "FollowIdMovement.h"
#include "Tile.h"
#include "LocalMap.h"
#include "GameObject.h"
#include "Utility.h"

const float EPSILON = 0.4f;

// set new direction and move
bool FollowIdMovement::Update(LocalMap& localmap, GameObject& my_obj, Graphics& my_graphics, float elapsedTime)
{
	setDir(localmap, my_obj);

	return Movement::Update(localmap, my_obj, my_graphics, elapsedTime);
}

void FollowIdMovement::setDir(LocalMap& localmap, GameObject& my_obj)
{
	// set base direction
	sf::Vector2f dir = localmap.getPosById(_id_to_follow) - my_obj.getPos();

	dir /= float(SCRN_TILE_SIZE); // normallize to squares

	// check if following_id is within range
	if (my_obj.getRadius()*1.8f/SCRN_TILE_SIZE < distance(dir, sf::Vector2f(0,0)) && distance(dir, sf::Vector2f(0,0)) < _radius)
	{
		// if it is, set the direction
		if (EPSILON < abs(dir.x))
			dir.x = abs(dir.x)/dir.x;
		if (EPSILON < abs(dir.y))
			dir.y = abs(dir.y)/dir.y;
		_direction = dir;
	}
	// if not, don't move.
	else _direction = sf::Vector2f(0,0);
}
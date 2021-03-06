#pragma once

// a Door changes the map when interacted with or stepped on.

#include <SFML/Graphics.hpp>
#include "LocalObject.h"
#include "ChangeMap.h"
#include <string>
#include "LocalMap.h"

using std::string;

class Door : public LocalObject
{
public:
	Door(const string& map, unsigned starting_tile) : LocalObject(shared_ptr<Script>(new ChangeMap(map, starting_tile)),
		 new NoGraphics, new NoMovement, true) {}
	Door(shared_ptr<Script>& script) : LocalObject(script,
		 new NoGraphics, new NoMovement, true) {}
	virtual bool act(LocalMap& localmap, HeroCharacter& hero) {	localmap.addScript(_script); return true; }
	virtual void StepOn(LocalMap& localmap, HeroCharacter& hero) { act(localmap, hero); }
};
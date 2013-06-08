#pragma once

#include "GameObject.h"
#include "Attack.h"
#include "Stats.h"

class Enemy : public GameObject
{
public:
	Enemy(Graphics* graphics = new NoGraphics, Movement* movement = new NoMovement) : GameObject(graphics, movement) {}
	virtual void act(LocalMap& localmap, GameObject& obj) { obj.act(localmap, *this); }
	virtual void StepOn(LocalMap& localmap, GameObject& obj) { obj.StepOn(localmap, *this); }
	virtual bool canStepOn(GameObject& obj) { return obj.canStepOn(*this); }

	virtual bool canStepOn(LocalObject& obj) { return false; }
	virtual bool canStepOn(HeroCharacter& obj) { return true; }
	virtual bool canStepOn(Enemy& obj) { return true; }

	virtual void act(LocalMap& localmap, HeroCharacter& hero) { }
	virtual void StepOn(LocalMap& localmap, HeroCharacter& obj);
	void attack(Stats& stats);
private:
	int _HP;
	Stats _stats;
};
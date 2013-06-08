#pragma once

#include <SFML/Graphics.hpp>

class Stats 
{
public:
	Stats(unsigned atk = 10, unsigned def = 10, unsigned luck = 10) : _ATK(atk), _DEF(def), _LUCK(luck) 
	{
		if (def == 0)
			_DEF = 1;
	}
	unsigned ATK() { return _ATK; }
	unsigned DEF() { return _DEF; }
	unsigned LUCK() { return _LUCK; }

private:
	unsigned _ATK;
	unsigned _DEF;
	unsigned _LUCK;
};

int calcDamage(Stats offense, Stats defense);
#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "StateParams.h"
#include "Flag.h"
#include "menu/Menu.h"

class Pause : public State
{
public:
	Pause() : _escape(false) {  }
	virtual void Enter(shared_ptr<StateParams>& params) { init(params); }
	virtual void Exit() { }
	virtual bool handleEvents(const Control& controls);
	virtual void Update(Controller& ctrl, float elapsedTime);
	virtual void Render(Controller& ctrl);

	void escape() { _escape = true; }

private:
	shared_ptr<Menu> _menu;
	bool _escape;

	void init(shared_ptr<StateParams>& params);

};
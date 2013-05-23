#pragma once

#include "StateParams.h"

class ParamsCtrl : public StateParams
{
public:
	ParamsCtrl(Controller& ctrl) : _ctrl(ctrl) { }
	virtual Controller& getCtrl() { return _ctrl; }
private:
	Controller& _ctrl;
};

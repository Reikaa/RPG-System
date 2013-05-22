#include "MainMenu.h"
#include "Controller.h"

bool MainMenu::handleEvents(const Control& controls)
{

	if (controls.isPressed(MOUSE_PRIMARY))
		_change_state.set();
			
	else if (controls.isPressed(MOUSE_SECONDARY))
		_color += 79 % 255;	

	return false;
}
void MainMenu::Update(Controller& ctrl, float elapsedTime)
{
	if (_change_state)
		ctrl.getStateMachine().Stack("localmap");

	_rect.setFillColor(sf::Color::Color(_color, 100, 100));
}

void MainMenu::Render(Controller& ctrl)
{
	ctrl.getWindow().draw(_rect);
}

void MainMenu::init()
{
	_rect.setPosition(0.f,0.f);
	_rect.setSize(sf::Vector2f(800.f, 600.f));
	_rect.setFillColor(sf::Color::Red);
}
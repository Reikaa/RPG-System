#include "Controller.h"
#include "MainMenu.h"
#include "GameMenu.h"
#include "LocalMap.h"

const int WINDOW_W = 960;
const int WINDOW_H = 640;
const unsigned FRAME_RATE = 60;

// tile size is 48x48 -> 32*1.5


Controller::Controller() {
	initWindow();
	initStateMachine();
}

void Controller::run()
{
	while (true)
	{
		float deltaTime = _clock.restart().asSeconds();

		sf::Event event;
		if (_window.pollEvent(event))
		{
			if (handleEvents(event))
				break;
			else _stateMachine.handleEvents(_controls);
		}

		_stateMachine.Update(*this,deltaTime);

		_window.setView(_view);
		_window.clear();
		_stateMachine.Render(*this);
		_window.display();

		// fps
		if ((deltaTime = _clock.getElapsedTime().asSeconds()) < 1.f/FRAME_RATE)
			sf::sleep(sf::seconds(1.f/FRAME_RATE - deltaTime));
	}
}

bool Controller::handleEvents(sf::Event& event)
{
	bool controls[NUM_OF_CONTROLS] = { false };
	if (event.type == sf::Event::Closed)
		return true;

	else if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Right)
			controls[MOUSE_SECONDARY] = true;
			
		else if (event.mouseButton.button == sf::Mouse::Left)
			controls[MOUSE_PRIMARY] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		controls[RIGHT] = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		controls[LEFT] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		controls[UP] = true;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		controls[DOWN] = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		controls[PRIMARY] = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		controls[SECONDARY] = true;

	_controls.setControls(controls);

	return false;
}

void Controller::initWindow() 
{
	// create window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	_window.create(sf::VideoMode(WINDOW_W, WINDOW_H), 
					"RPG", sf::Style::Default, settings);
	
	_window.setVerticalSyncEnabled(true); // set refresh rate as screen's refresh rate
	_window.setJoystickThreshold(10000); // joystick threshold
	_window.setFramerateLimit(FRAME_RATE);
	

	// create view
	_view.setCenter(WINDOW_W/2.f, WINDOW_H/2.f);
	_view.setSize(float(WINDOW_W), float(WINDOW_H));
	//_view.zoom(1.5f);

	_window.setView(_view);
}

void Controller::initStateMachine()
{
	_stateMachine.Add("mainmenu", new MainMenu);
	_stateMachine.Add("gamemenu", new GameMenu);
	_stateMachine.Add("localmap", new LocalMap);
	_stateMachine.Change("localmap");
}
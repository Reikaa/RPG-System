#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "StateParams.h"
#include "Flag.h"
#include "Map.h"
#include "GameObject.h"
#include "LocalObject.h"
#include "Script.h"
#include <queue>
#include "FadeEffect.h"

using std::queue;
using std::shared_ptr;

class LocalMap : public State
{
public:
	LocalMap();
	virtual void Enter(shared_ptr<StateParams>& params) { _first_update = false; init(params); }
	virtual void Exit() { }
	virtual bool handleEvents(const Control& controls);
	virtual void Update(Controller& ctrl, float elapsedTime);
	virtual void Render(Controller& ctrl);
//	shared_ptr<Map> map() const { return _map; }
	void addScript(shared_ptr<Script>& script);
	void NextScript(Controller& ctrl);
	void addCommand(shared_ptr<Script>& script);
	void NextCommand(Controller& ctrl);

	void addGameObject(shared_ptr<GameObject>& obj, unsigned pos) { _map->addGameObject(obj, pos); }
	void addGameObject(shared_ptr<GameObject>& obj, const sf::Vector2f& pos) { _map->addGameObject(obj, pos); }
	void remGameObject(GameObject* obj) { _map->remGameObject(obj); }
	const sf::Vector2f getPosById(int id) { return _map->getPosById(id); }

	bool canStepOn(GameObject& obj) { return _map->canStepOn(obj); }
	void Step(GameObject& obj) { _map->Step(*this, obj); }
	bool Act(GameObject& obj, sf::FloatRect& box) { return _map->Act(*this, obj, box); }

private:
	Flag _change_state;
	queue<shared_ptr<Script>> _scripts;
	queue<shared_ptr<Script>> _commands;
	void init(shared_ptr<StateParams>& params);
	shared_ptr<Map> _map;

	Fade _fade;
	bool _first_update;
};
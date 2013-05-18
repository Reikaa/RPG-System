#pragma once

#include <SFML\Graphics.hpp>
#include "Macros.h"

class Graphics
{
public:
	Graphics(sf::Texture* texture, sf::Vector2i loc_on_texture, const sf::Vector2u& size);
	virtual ~Graphics() { }
	virtual void Update();
	void Render(sf::RenderWindow& window);
	void move(const sf::Vector2f& direction);
	void setPos(const sf::Vector2f& pos);
	void setDisplay(bool dis);

private:
	sf::Texture* _texture;
	sf::Sprite _sprite;
	sf::Vector2i _loc_on_texture;
	unsigned _animation;
	float _animation_clock;
	bool _display;
};
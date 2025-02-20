#pragma once
#include "Window.h"
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void update();
	void render();

	sf::Time getElapsed();
	void restartClock();

	void moveSprite();

	Window* getWindow();

private:
	Window _window;
	//sf::Clock _clock;

	sf::Texture _texture;
	sf::Sprite _sprite;
};
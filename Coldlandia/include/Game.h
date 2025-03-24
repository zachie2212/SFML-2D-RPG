#pragma once
#include "Window.h"
#include <iostream>
#include <EntityBase.h>
#include <EventManager.h>
#include <SharedContext.h>
#include <TileMap.h>

class Game {
public:
	Game();
	~Game();

	void update();
	void render();

	sf::Time getElapsed();
	void restartClock();

	Window* getWindow();

private:
	//sf::Clock _clock;

	TileMap _map;
	EntityBase _e;
	SharedContext _context;
};
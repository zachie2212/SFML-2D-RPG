#include "Game.h"

const std::string title = "Coldlandia RPG";

Game::Game()
{
	Window* win = new Window(title, { 32*16, 32*8 });
	_context = SharedContext(win, new EventManager(win, &_e));
	_e.init("resources/textures/player/asmund_single_sprite_v1.png");
	if (!_map.load("resources/textures/tilemaps/vertex-array-tilemap-tileset.png", { 32, 32 }, "resources/maps/test0.txt"))
	{
		std::cout << "Error loading tile map resources.\r\n";
	}
}

Game::~Game()
{
	_context.window->close();
}

void Game::update()
{
	_context.event_manager->handleEvents();
}

void Game::render()
{
	Window* w = _context.window;
	w->beginDraw();
	sf::RenderWindow* rw = w->getRenderWindow();
	// draw here
	_map.draw(*rw, sf::RenderStates());
	_e.draw(_context.window);
	_context.window->endDraw();
}

sf::Time Game::getElapsed()
{
	return sf::Time();
}

void Game::restartClock()
{
}

Window* Game::getWindow()
{
	return _context.window;
}

#include "Game.h"

const std::string title = "Coldlandia RPG";

Game::Game()
{
	Window* win = new Window(title, { 800, 600 });
	_context = SharedContext(win, new EventManager(win, &_e));
	_e.init("resources/textures/player/asmund_single_sprite_v1.png");
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
	_context.window->beginDraw();
	// draw here
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

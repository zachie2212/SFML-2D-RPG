#include "Game.h"

const std::string title = "Coldlandia RPG";

Game::Game() : _window(title, { 800, 600 }), 
			_texture("resources/textures/player/asmund_single_sprite_v1.png"), 
			_sprite(_texture)
{
}

Game::~Game()
{
	_window.close();
}

void Game::update()
{
	_window.update();
}

void Game::render()
{
	_window.beginDraw();
	// draw here
	_window.getRenderWindow()->draw(_sprite);
	_window.endDraw();
}

sf::Time Game::getElapsed()
{
	return sf::Time();
}

void Game::restartClock()
{
}

void Game::moveSprite()
{
}

Window* Game::getWindow()
{
	return &_window;
}

#include "EventManager.h"
#include <iostream>

/* Default constructor */
EventManager::EventManager()
	: _window(nullptr), _player(nullptr)
{
}

/* Main constructor */
EventManager::EventManager(Window* window, EntityBase* e)
	: _window(window), _player(e)
{
}

EventManager::~EventManager()
{
	_window->close();
}

/* Event handlers */
void EventManager::onClose()
{
	_window->close();
}

void EventManager::onKeyPressed(const sf::Event::KeyPressed* key_pressed)
{
	switch (key_pressed->scancode) {
	case sf::Keyboard::Scancode::Escape: _window->close(); break;
	case sf::Keyboard::Scancode::F5: _window->toggleFullscreen(); break;
	}
}

void EventManager::onMouseButtonPressed(const sf::Event::MouseButtonPressed* mouse_pressed)
{
	std::cout << "Mouse button pressed" << std::endl;
}

void EventManager::movePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		_player->move(5, EntityBase::Direction::UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		_player->move(5, EntityBase::Direction::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		_player->move(5, EntityBase::Direction::DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		_player->move(5, EntityBase::Direction::RIGHT);
	}
}

void EventManager::handleEvents()
{
	sf::RenderWindow* window = _window->getRenderWindow();

	while (const std::optional<sf::Event> event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			onClose();
		}
		else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
			onKeyPressed(key_pressed);
		}
		else if (const auto* mouse_pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
			onMouseButtonPressed(mouse_pressed);
		}
		else
		{
			//std::cout << "Unhandled event type" << std::endl;
		}
	}

	movePlayer();
}
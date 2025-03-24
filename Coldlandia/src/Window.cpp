#include "Window.h"

Window::Window()
{
	setup("Coldlandia RPG", { 800,600 });
}

Window::Window(const std::string& title, const sf::Vector2u& size)
{
	setup(title, size);
}

Window::~Window()
{
	close();
}

void Window::beginDraw()
{
	_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
	_window.display();
}

void Window::setup(const std::string& title, const sf::Vector2u& size)
{
	_window_title = title;
	_window_size = size;
	_is_fullscreen = false;
	_is_done = false;
	create();
}

void Window::create()
{
	auto style = sf::Style::Default;
	auto state = _is_fullscreen ? sf::State::Fullscreen : sf::State::Windowed;
	_window.create(sf::VideoMode(_window_size), _window_title, style, state);
	_window.setVerticalSyncEnabled(true);
}

void Window::close()
{
	_is_done = true;
	_window.close();
}

bool Window::isDone() { return _is_done; }
bool Window::isFullscreen() { return _is_fullscreen; }

bool Window::isFocused()
{
	return _is_focused;
}

sf::RenderWindow* Window::getRenderWindow() { return &_window; }

sf::Vector2u Window::getWindowSize() { return _window_size; }

void Window::toggleFullscreen() {
	_is_fullscreen = !_is_fullscreen;
	_window.close();
	create();
}
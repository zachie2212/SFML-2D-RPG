#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Window {
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void beginDraw();
	void endDraw();

	void update();

	bool isDone();
	bool isFullscreen();
	bool isFocused();

	void toggleFullscreen();
	void close();

	sf::RenderWindow* getRenderWindow();
	sf::Vector2u getWindowSize();
private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void create();

	sf::RenderWindow _window;
	sf::Vector2u _window_size;
	std::string _window_title;
	bool _is_done;
	bool _is_fullscreen;
	bool _is_focused;
};
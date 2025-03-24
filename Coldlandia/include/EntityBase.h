#pragma once

#include "SFML/Graphics.hpp"
#include "Window.h"

/* Abstract base entity class. */
class EntityBase
{
public:
	enum Direction {
		UP, DOWN, LEFT, RIGHT,
	};

	EntityBase();

	void init(std::string texture_path);
	void init(std::string texture_path, std::string name, sf::FloatRect hitbox);
	void draw(Window* window);
	void move(float amount, Direction direction);

private:
	// required
	sf::Texture _texture;
	sf::Sprite _sprite;
	// Default is bounding box of _sprite.
	sf::FloatRect _hitbox;
	// Default is _texture_name.
	std::string _name;
	
	std::string _texture_folder;
	std::string _texture_name;

	// Extract texture folder and name from texture path string.
	void pathInit(std::string texture_path);
	// Load texture from file path
	void load(std::string texture_path);
};


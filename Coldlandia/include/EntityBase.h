#pragma once

#include "SFML/Graphics.hpp"
#include <Window.h>

/* Abstract base entity class. */
class EntityBase
{
public:
	enum Direction {
		UP, DOWN, LEFT, RIGHT,
	};
	virtual void init(std::string texture_path);
	virtual void init(std::string texture_path, std::string name, sf::FloatRect hitbox);
	virtual void draw(Window* window);
	virtual void move(float amount, Direction direction);
private:
	// required
	sf::Sprite _sprite;
	sf::Texture _texture;
	// Default is bounding box of _sprite.
	sf::FloatRect _hitbox;
	// Default is _texture_name.
	std::string _name;
	
	std::string _texture_folder;
	std::string _texture_name;

	// Extract texture folder and name from texture path.
	void pathInit(std::string texture_path);
};


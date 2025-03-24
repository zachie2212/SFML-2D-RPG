#include "EntityBase.h"
#include <iostream>

EntityBase::EntityBase() : _texture("resources/textures/player/square.png"), _sprite(_texture)
{
}

void EntityBase::load(std::string texture_path) {
	pathInit(texture_path);

	if (!_texture.loadFromFile(texture_path)) {
		std::cout << "Failed to load Texture" << std::endl;
	}
	_texture.setRepeated(false);
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
}

void EntityBase::init(std::string texture_path)
{
	load(texture_path);
	_hitbox = _sprite.getGlobalBounds();
	_name = _texture_name;
}

void EntityBase::init(std::string texture_path, std::string name, sf::FloatRect hitbox)
{
	load(texture_path);
	_hitbox = hitbox;
	_name = name;
}

void EntityBase::draw(Window* window)
{
	window->getRenderWindow()->draw(_sprite);
}

void EntityBase::move(float amount, Direction direction)
{
	sf::Vector2f pos = _sprite.getPosition();
	switch (direction) {
	case UP:
		_sprite.setPosition({ pos.x, pos.y - amount });
		break;
	case DOWN:
		_sprite.setPosition({ pos.x, pos.y + amount });
		break;
	case LEFT:
		_sprite.setPosition({ pos.x - amount, pos.y});
		break;
	case RIGHT:
		_sprite.setPosition({ pos.x + amount, pos.y });
	}
	/*std::cout << "Sprite Position: (" << _sprite.getPosition().x << ", " << _sprite.getPosition().y << ")" << std::endl;*/
}

void EntityBase::pathInit(std::string texture_path)
{
	size_t pos = texture_path.find_last_of("/");
	_texture_folder = texture_path.substr(0, pos);
	_texture_name = texture_path.substr(pos + 1);
}

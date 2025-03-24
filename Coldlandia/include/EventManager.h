#pragma once

#include "Window.h"
#include "EntityBase.h"

class EventManager {
public:
    EventManager();
    EventManager(Window* window, EntityBase* e);
    ~EventManager();
    void handleEvents();

private:
    Window* _window;
    EntityBase* _player;

    void onClose();
    void onKeyPressed(const sf::Event::KeyPressed* keyPressed);
    void onMouseButtonPressed(const sf::Event::MouseButtonPressed* mouse_pressed);
    void movePlayer();
};

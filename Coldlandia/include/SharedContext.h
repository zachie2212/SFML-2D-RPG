#pragma once
#include "Window.h"
#include "EventManager.h"
struct SharedContext {
	SharedContext()
		:window(nullptr),
		event_manager(nullptr) {
	}
	SharedContext(Window* window, EventManager* event_manager) {
		this->window = window;
		this->event_manager = event_manager;
	}
	Window* window;
	EventManager* event_manager;
};
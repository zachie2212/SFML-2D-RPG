#include "Game.h"

int main(int argc, char* argv[]) {
	Game game;
	while (!game.getWindow()->isDone()) {
		game.update();
		game.render();
	}
}
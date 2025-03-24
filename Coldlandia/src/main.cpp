#include "Game.h"

int main(int argc, char* argv[]) {
	Game game;
	while (!game.getWindow()->isDone()) {
		game.update();
		game.render();
	}




    // TEST
    //sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    //sf::Texture texture;

    //if (!texture.loadFromFile("resources/textures/player/square.png"))
    //{
    //    std::cout << "tex error\n";
    //}

    //sf::Sprite sprite(texture);
    //if (!texture.loadFromFile("resources/textures/player/asmund_single_sprite_v1.png"))
    //{
    //    std::cout << "tex error\n";
    //}
    //sprite.setTexture(texture);
    //sprite.setPosition({ 32,32 });

    //// run the program as long as the window is open
    //while (window.isOpen())
    //{
    //    // check all the window's events that were triggered since the last iteration of the loop
    //    while (const std::optional event = window.pollEvent())
    //    {
    //        // "close requested" event: we close the window
    //        if (event->is<sf::Event::Closed>())
    //            window.close();
    //    }

    //    // clear the window with black color
    //    window.clear(sf::Color::Black);

    //    // draw everything here...
    //    window.draw(sprite);

    //    // end the current frame
    //    window.display();
    //}
}
#include <SFML/Graphics.hpp>
#include "GameWrapper.h"
#include <iostream>

int main(void)
{
	srand(time(NULL));//random


	//background
	sf::Texture texture;
	
	if (!texture.loadFromFile("background.png")) 
	{
		std::cout << "Texture not loaded" << std::endl;
	}

	sf::Event event;
	bool gameStart = false;


	//game screen
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Burgeon");
	window.setFramerateLimit(120);
	
	while (window.isOpen()) {
		while (window.isOpen() && !gameStart) {//start screen loop 
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::Space)
						gameStart = true;
				}

			}

			window.clear();
			sf::Sprite sprite(texture);
			sprite.setScale(sf::Vector2f(.6666, .6666));
			window.draw(sprite);

			window.display();
		}
		GameWrapper gw(window);

		while (window.isOpen() && !gw.isGameOver())//main game loop
		{

			gw.update(window);

			gw.render(window);

		}
		gameStart = false;
	}

	return(0);
}
#include <SFML/Graphics.hpp>
#include "GameWrapper.h"
#include <iostream>

int main(void)
{
	srand(time(NULL));//random



	sf::RenderWindow start_window(sf::VideoMode(1280, 720), "Burgeon");

	
	sf::Texture texture;
	
	if (!texture.loadFromFile("background.png")) //need to get png file
	{
		std::cout << "Texture not loaded" << std::endl;
	 }

		sf::Event event;
		while (start_window.isOpen())
		{
			while (start_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || (event.key.code == sf::Keyboard::Space))
					start_window.close();

			}

			start_window.clear();
			sf::Sprite sprite(texture);
			sprite.setScale(sf::Vector2f(.6666, .6666));
			start_window.draw(sprite);
			
			start_window.display();
		}
	//game screen
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Burgeon2");

	window.setFramerateLimit(120);
	
	GameWrapper gw(window);

	while (window.isOpen())
	{
		
		gw.update(window);

		gw.render(window);
		
	}

	return(0);
}
#include <SFML/Graphics.hpp>
#include "GameWrapper.h"
#include <iostream>

int main(void)
{
	srand(time(NULL));//random

	sf::RenderWindow start_window(sf::VideoMode(1280, 720), "Burgeon");

	//background
	sf::Texture texture;
	
	if (!texture.loadFromFile("background.png")) 
	{
		std::cout << "Texture not loaded" << std::endl;
	 }

	//textbox
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Font Failed";
	}
	else
	{
		text.setPosition(755, 100);
		text.setFont(font);
		text.setCharacterSize(20);
		text.setColor(sf::Color::Black);
		text.setString("Welcome to Burgeon!\n\n"
			"Rules of the Game:\n"
			"You are the fireball and you need to collect logs to grow.\n"
			"Watch out for the water droplets or you will shrink!\n"
			"Shoot fire at your enemy to kill them (See controls)\n"
			"If you get too small, it's Game Over!");
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
			start_window.draw(text);
			
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
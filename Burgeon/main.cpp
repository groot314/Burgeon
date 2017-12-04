#include <SFML/Graphics.hpp>
#include "GameWrapper.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));//random


	//background
	sf::Texture texture;
	
	if (!texture.loadFromFile("background.png")) 
	{
		std::cout << "Texture not loaded" << std::endl;
	}

	sf::Texture gameover;
	if (!gameover.loadFromFile("gameover.png"))
	{
		std::cout << "Gameover not loaded" << std::endl;
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
		bool game_over= gw.isGameOver();
		while (window.isOpen() && game_over) {
			//score on gameover screen
			sf::Text text;
			sf::Font font;
			if (!font.loadFromFile("LeagueGothic.otf"))
			{
				// doesn't load
				std::cout << "League Gothic failed";

			}

			else {
				int i = gw.getScore();
				std::string s =std::to_string(i);
				text.setFont(font);
				text.setString("Score: " + s);
				//text.setString(s);
				text.setCharacterSize(75);
				text.setColor(sf::Color::White);
				text.setPosition(520, 460);
			}
			text.setFont(font);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::R) {
						gameStart = true;
						game_over = false;
					}
					else if (event.key.code == sf::Keyboard::Space) {
						gameStart = false;
						game_over = false;
					}
				}

			}

			window.clear();
			sf::Sprite game(gameover);
			game.setScale(sf::Vector2f(.6666, .6666));
			window.draw(game);
			window.draw(text);
			window.display();

			
		}
		
	}

	return(0);
}
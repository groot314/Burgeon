#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class Log : public sf::Sprite {

public:

	Log(sf::RenderWindow & window);

	void respawnLog();

	bool checkPlayerCollison(Player &player);


private:
	sf::Vector2f windowSize;

	static sf::Sprite getSprite() {
		static sf::Sprite s;

		static sf::Texture texture;
		if (!texture.loadFromFile("logs.png")) {
			std::cout << "Texture not loaded" << std::endl;
		}
		texture.setSmooth(true);
		s.setTexture(texture);

		return s;
	}
};
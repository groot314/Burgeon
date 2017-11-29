#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class Log : public sf::RectangleShape {

public:

	Log(sf::RenderWindow & window);

	void respawnLog();

	bool checkPlayerCollison(Player &player);


private:
	sf::Vector2u windowSize;
};
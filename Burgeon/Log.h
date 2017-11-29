#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class Log : public sf::RectangleShape {

public:

	Log(sf::RenderWindow & window);

	bool checkPlayerCollison(Player &player);


private:

};
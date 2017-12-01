#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"

class heatSeekingEnemy : public Enemy {

public:

	heatSeekingEnemy(sf::RenderWindow &window);

	void movement(Player player);

private:

	sf::Vector2u windowSize;

	double speed;
};
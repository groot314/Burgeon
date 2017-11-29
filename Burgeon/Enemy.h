#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Fireball.h"

class Enemy : public sf::CircleShape {
	
public:

	Enemy(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error"));

	bool outOfBounds();

	void movement();
	bool checkPlayerCollision(Player &player);
	bool checkFireballCollison(FireBall &fireball);

private:
	sf::Vector2u windowSize;

	int xMovement;
	int yMovement;
};
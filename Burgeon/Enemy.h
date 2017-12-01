#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Fireball.h"

class Enemy : public sf::Sprite {
	
public:

	Enemy(sf::RenderWindow &window);

	bool isOutOfBounds();

	virtual void movement();
	bool checkPlayerCollision(Player &player);
	bool checkFireballCollison(FireBall &fireball);

private:
	sf::Vector2f windowSize;

	int xMovement;
	int yMovement;

	double speed;

	static sf::Sprite getSprite() {
		static sf::Sprite s;

		static sf::Texture texture;
		if (!texture.loadFromFile("enemy.png")) {
			std::cout << "Texture not loaded" << std::endl;
		}
		texture.setSmooth(true);
		s.setTexture(texture);

		return s;
	}
};
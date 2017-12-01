#pragma once
#include <vector>
#include <iostream>
#include "Fireball.h"
#include <SFML\Graphics.hpp>

class Player : public sf::Sprite {

public:
	Player(sf::RenderWindow &window, sf::Vector2f pos = { 0,0 });

	void setSpeed(double speed);
	double getSpeed();

	void controlMovement(sf::RenderWindow &window);
	void controlShoot(sf::Event &event, std::vector<FireBall*> & fireBalls);

	bool isTooSmall();
	bool isTooBig();

	void isHit();
	void gotLog();

private:
	sf::Vector2f windowSize;

	double speed;

	void shoot(std::vector<FireBall*> & fireBalls, int direction);

	static sf::Sprite getSprite() {
		static sf::Sprite s;
		
		static sf::Texture texture;
		if (!texture.loadFromFile("player.png")) {
			std::cout << "Texture not loaded" << std::endl;
		}
		texture.setSmooth(true);
		s.setTexture(texture);

		return s;
	}
};
#pragma once
#include <vector>
#include "Fireball.h"
#include <SFML\Graphics.hpp>

class Player : public sf::CircleShape {

public:
	Player(sf::RenderWindow &window, sf::Vector2f pos = { 0,0 });

	void setSpeed(double speed);
	double getSpeed();

	void controlMovement();
	void controlShoot(sf::Event &event, std::vector<FireBall*> & fireBalls);

	void isHit();
	void gotLog();

private:
	sf::Vector2u windowSize;

	double speed;

	void shoot(std::vector<FireBall*> & fireBalls, int direction);
};
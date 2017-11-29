#include "Player.h"



Player::Player(sf::RenderWindow & window, sf::Vector2f pos):CircleShape(50) {
	this->setPosition(pos);
	this->setFillColor(sf::Color::Red);
	this->setSpeed(.0625);
}

void Player::setSpeed(double speed)
{
	this->speed = speed;
}

double Player::getSpeed()
{
	return speed;
}

void Player::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//up
		this->move(0*speed,-1*speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//left
		this->move(-1*speed,0*speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//right
		this->move(1*speed,0*speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
		this->move(0*speed,1*speed);
	}
}


void Player::isHit()
{
	this->setScale(sf::Vector2f(.95,.95));

	//add blue overlay on texture
}

void Player::gotLog()
{
	this->setScale(sf::Vector2f(1.05, 1.05));
}

void Player::shot()
{
	this->setScale(sf::Vector2f(.975, .975));
}

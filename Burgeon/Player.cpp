#include "Player.h"



Player::Player(sf::RenderWindow & window, sf::Vector2f pos):CircleShape(50) {
	this->setPosition(pos);
	this->setFillColor(sf::Color::Red);
}

void Player::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//up
		this->move({0,-1});
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//left
		this->move({ -1,0 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//right
		this->move({ 1,0 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
		this->move({ 0,1 });
	}
}


void Player::isHit()
{
	this->setRadius(this->getRadius() - 2);

	//add blue overlay on texture
}

void Player::gotLog()
{
	this->setRadius(this->getRadius() + 2);
}

void Player::shot()
{
	this->setRadius(this->getRadius() - 2);
}

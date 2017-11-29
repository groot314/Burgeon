#include "Player.h"



Player::Player(sf::RenderWindow & window, sf::Vector2f pos):CircleShape(50) {
	this->setPosition(pos);
	this->setFillColor(sf::Color::Red);
	this->setSpeed(1.75);

	windowSize = window.getSize();
}

void Player::setSpeed(double speed)
{
	this->speed = speed;
}

double Player::getSpeed()
{
	return speed;
}

void Player::controlMovement(sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//up
		if (this->getPosition().y>=0)
		{
			this->move(0 * speed, -1 * speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//left
		if (this->getPosition().x >= 0)
		{
			this->move(-1 * speed, 0 * speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//right
		if (this->getPosition().x <= window.getSize().x - (this->getRadius()))
		{
			this->move(1 * speed, 0 * speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
		if ( this->getPosition().y <= window.getSize().y- (this->getRadius()))
		{
			this->move(0 * speed, 1 * speed);
		}
	}
}

void Player::controlShoot(sf::Event &event, std::vector<FireBall*> & fireBalls)
{
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up) {//up
			shoot(fireBalls,1);
		}
		if (event.key.code == sf::Keyboard::Left) {//left
			shoot(fireBalls, 2);
		}
		if (event.key.code == sf::Keyboard::Right) {//right
			shoot(fireBalls, 3);
		}
		if (event.key.code == sf::Keyboard::Down) {//down
			shoot(fireBalls, 4);
		}
	}
}

bool Player::isTooSmall()
{
	return (this->getScale().x < 0.5);
}


void Player::isHit()
{
	this->scale(sf::Vector2f(.95,.95));

	//add blue overlay on texture
}

void Player::gotLog()
{
	this->scale(sf::Vector2f(1.05, 1.05));
}

void Player::shoot(std::vector<FireBall*> & fireBalls, int direction)
{
	this->scale(sf::Vector2f(.95,.95));

	FireBall *newFire = new FireBall({this->getPosition().x +( this->getRadius()/2),this->getPosition().y + (this->getRadius()/2) }, direction);

	fireBalls.push_back(newFire);
}

#include "Player.h"



Player::Player(sf::RenderWindow & window, sf::Vector2f pos):Sprite(getSprite()){
	this->setPosition(pos);
	this->scale({1.5,1.5});
	this->setColor(sf::Color(255, 255, 255, 200));

	this->setSpeed(1.75);

	windowSize = window.getDefaultView().getSize();
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
		if (this->getPosition().x <= windowSize.x -this->getTextureRect().width*this->getScale().x)
		{
			this->move(1 * speed, 0 * speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
		if ( this->getPosition().y <= windowSize.y - this->getTextureRect().height*this->getScale().y)
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

bool Player::isTooBig()
{
	return (this->getScale().x > 2.5);
}


void Player::isHit()
{
	this->scale(sf::Vector2f(.90,.90));

	//add blue overlay on texture
}

void Player::gotLog()
{
	if (!isTooBig()) {
		this->scale(sf::Vector2f(1.05, 1.05));
	}
}

void Player::shoot(std::vector<FireBall*> & fireBalls, int direction)
{
	this->scale(sf::Vector2f(.95,.95));

	FireBall *newFire = new FireBall(windowSize,{this->getPosition().x,this->getPosition().y}, direction);

	fireBalls.push_back(newFire);
}

#include "Player.h"



Player::Player(sf::RenderWindow & window, sf::Vector2f pos):Sprite(getSprite()){
	health = 50;

	this->setPosition(pos);
	setHealthSize();
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

bool Player::controlShoot(sf::Event &event, std::vector<FireBall*> & fireBalls)
{
	bool shot = false;
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up) {//up
			shot = shoot(fireBalls,1);
		}
		if (event.key.code == sf::Keyboard::Left) {//left
			shot = shoot(fireBalls, 2);
		}
		if (event.key.code == sf::Keyboard::Right) {//right
			shot = shoot(fireBalls, 3);
		}
		if (event.key.code == sf::Keyboard::Down) {//down
			shot = shoot(fireBalls, 4);
		}
	}
	return shot;
}

int Player::getHealth()
{
	return health;
}

bool Player::isTooSmall()
{
	return (health <= 0);
}

bool Player::isTooBig()
{
	return (health > 300);
}

bool Player::isDead()
{
	return (health < 0);
}


void Player::isHit()
{
	health = health - 20;
	setHealthSize();

	//add blue overlay on texture
}

void Player::gotLog()
{
	if (!isTooBig()) {
		health = health + 10;
		setHealthSize();
	}
}

bool Player::shoot(std::vector<FireBall*> & fireBalls, int direction)
{
	health = health - 10;
	setHealthSize();

	FireBall *newFire = new FireBall(windowSize,{this->getPosition().x + ((this->getTextureRect().width*this->getScale().x) /2), this->getPosition().y + ((this->getTextureRect().height*this->getScale().y) /2)}, direction);

	fireBalls.push_back(newFire);

	return true;
}

void Player::setHealthSize()
{
	this->setScale(sf::Vector2f((health*.0025) + .35, (health*.0025) + .35));
}

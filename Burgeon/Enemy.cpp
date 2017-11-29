#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow & window):CircleShape(15) {

	windowSize = window.getSize();

	int edge = rand() % 4;
	int xPos = (rand() % 100) * window.getSize().x * .01;
	int yPos = (rand() % 100) * window.getSize().y * .01;

	xMovement = 0;
	yMovement = 0;

	if (edge == 0) { // left
		this->setPosition(sf::Vector2f(0, yPos));
		// move right
		xMovement = 1;
	}
	else if (edge == 1) { // top
		this->setPosition(sf::Vector2f(xPos, 0));
		// move down
		yMovement = 1;
	}
	else if (edge == 2) { // right
		this->setPosition(sf::Vector2f(window.getSize().x, yPos));
		// move left
		xMovement = -1;
	}
	else { // bottom
		this->setPosition(sf::Vector2f(xPos, window.getSize().y));
		// move up
		yMovement = -1;
	}

	this->setFillColor(sf::Color::Blue);
}

bool Enemy::outOfBounds()
{
	if (this->getPosition().x > windowSize.x) {
		return true;
	}
	if (this->getPosition().y > windowSize.y) {
		return true;
	}

	return false;
}

void Enemy::movement()
{
	this->move(xMovement * 0.05, yMovement * 0.05);
}

bool Enemy::checkPlayerCollision(Player & player)
{
	if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
		return true;
	}
	return false;
}

bool Enemy::checkFireballCollison(FireBall & fireball)
{
	if (this->getGlobalBounds().intersects(fireball.getGlobalBounds())) {
		return true;
	}
	return false;
}

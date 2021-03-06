#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow & window):Sprite(getSprite()) {

	windowSize = window.getDefaultView().getSize();

	speed = 1.25;

	int edge = rand() % 4;
	int xPos = (rand() % 100) * window.getDefaultView().getSize().x * .01;
	int yPos = (rand() % 100) * window.getDefaultView().getSize().y * .01;

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
		this->setPosition(sf::Vector2f(window.getDefaultView().getSize().x, yPos));
		// move left
		xMovement = -1;
	}
	else { // bottom
		this->setPosition(sf::Vector2f(xPos, window.getDefaultView().getSize().y));
		// move up
		yMovement = -1;
	}

}

bool Enemy::isOutOfBounds()
{
	if (this->getPosition().x > windowSize.x) {
		return true;
	}
	if (this->getPosition().y > windowSize.y) {
		return true;
	}
	if (this->getPosition().x < -this->getTextureRect().width) {
		return true;
	}
	if (this->getPosition().y < -this->getTextureRect().height) {
		return true;
	}

	return false;
}

void Enemy::movement()
{
	this->move(xMovement * speed, yMovement * speed);
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

#include "heatSeekingEnemy.h"

heatSeekingEnemy::heatSeekingEnemy(sf::RenderWindow & window):Enemy(window)
{

	windowSize = window.getDefaultView().getSize();

	speed = 1.25;

	int edge = rand() % 4;
	int xPos = (rand() % 100) * window.getDefaultView().getSize().x * .01;
	int yPos = (rand() % 100) * window.getDefaultView().getSize().y * .01;


	if (edge == 0) { // left
		this->setPosition(sf::Vector2f(0, yPos));
		// move right
	}
	else if (edge == 1) { // top
		this->setPosition(sf::Vector2f(xPos, 0));
		// move down
	}
	else if (edge == 2) { // right
		this->setPosition(sf::Vector2f(window.getDefaultView().getSize().x, yPos));
		// move left
	}
	else { // bottom
		this->setPosition(sf::Vector2f(xPos, window.getDefaultView().getSize().y));
		// move up
	}

}

void heatSeekingEnemy::movement(Player player)
{
	int pX = player.getPosition().x;
	int pY = player.getPosition().y;
	
	int eX = this->getPosition().x;
	int eY = this->getPosition().y;

	int xCoord = pX - eX;
	int yCoord = pY - eY;

	double denom = sqrt((xCoord*xCoord) + (yCoord*yCoord));

	double unitX = xCoord / denom;
	double unitY = yCoord / denom;

	this->move(unitX * speed, unitY * speed);

}

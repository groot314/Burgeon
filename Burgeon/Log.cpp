#include "Log.h"

Log::Log(sf::RenderWindow & window) {
	windowSize = window.getSize();

	this->setSize(sf::Vector2f(40, 40));
	this->setFillColor(sf::Color::Magenta);
	this->respawnLog();
}

void Log::respawnLog()
{
	int xPos;
	int yPos;
	int xNum = rand() % 100;
	int yNum = rand() % 100;

	xPos = xNum * 0.01 * windowSize.x;
	yPos = yNum * 0.01 * windowSize.y;

	this->setSize(sf::Vector2f(40, 40));
	this->setFillColor(sf::Color::Magenta);
	this->setPosition(sf::Vector2f(xPos, yPos));
}

bool Log::checkPlayerCollison(Player & player)
{
	if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
		return true;
	}
	return false;
}

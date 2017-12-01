#include "Log.h"

Log::Log(sf::RenderWindow & window):Sprite(getSprite()) {
	windowSize = window.getSize();

	this->scale({1.5,1.5});

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

	this->setPosition(sf::Vector2f(xPos, yPos));
}

bool Log::checkPlayerCollison(Player & player)
{
	if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
		return true;
	}
	return false;
}

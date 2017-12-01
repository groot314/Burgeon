#include "Log.h"

Log::Log(sf::RenderWindow & window):Sprite(getSprite()) {
	windowSize = window.getDefaultView().getSize();

	this->scale({1.5,1.5});

	this->respawnLog();
}

void Log::respawnLog()
{
	int xPos = rand() % (int)(windowSize.x - this->getTextureRect().width);
	int yPos = rand() % (int)(windowSize.y - this->getTextureRect().height);

	this->setPosition(sf::Vector2f(xPos, yPos));
}

bool Log::checkPlayerCollison(Player & player)
{
	if (this->getGlobalBounds().intersects(player.getGlobalBounds())) {
		return true;
	}
	return false;
}

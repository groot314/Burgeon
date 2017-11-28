#include "GameWrapper.h"

void GameWrapper::update(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void GameWrapper::render(sf::RenderWindow & window)
{
	window.clear();
	window.draw(player);
	window.display();
}

GameWrapper::~GameWrapper()
{
}

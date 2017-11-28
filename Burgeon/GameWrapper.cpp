#include "GameWrapper.h"

GameWrapper::GameWrapper()
{
}

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
	//draw objects
	window.display();
}

GameWrapper::~GameWrapper()
{
}

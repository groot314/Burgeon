#include "GameWrapper.h"

void GameWrapper::update(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}


	player->control();
	for (int i = 0; i < fireBalls.size(); i++) {//move all fireBalls
		fireBalls[i]->movement();
	}
	for (int i = 0; i < enemys.size(); i++) {//move all enemeys
		enemys[i]->movement();
	}
}

void GameWrapper::render(sf::RenderWindow & window)
{
	window.clear();
	window.draw(*player);

	for (int i = 0; i < logs.size(); i++) {//draw all logs
		window.draw(*logs[i]);
	}
	for (int i = 0; i < fireBalls.size(); i++) {//draw all fireBalls
		window.draw(*fireBalls[i]);
	}
	for (int i = 0; i < enemys.size(); i++) {//draw all enemeys
		window.draw(*enemys[i]);
	}

	window.display();
}

GameWrapper::~GameWrapper()
{
}

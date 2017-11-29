#include "GameWrapper.h"

void GameWrapper::update(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();


	}



	player->controlMovement(window);
	if (!player->isTooSmall()) {
		player->controlShoot(event, fireBalls);
	}

	for (int i = 0; i < fireBalls.size(); i++) {//move all fireBalls
		fireBalls[i]->movement();
		
	}
	for (int i = 0; i < enemys.size(); i++) {//move all enemeys
		enemys[i]->movement();
		
		if (enemys[i]->checkPlayerCollision(*player)) {
			if (!player->isTooSmall()) {
				player->isHit();
			}
			else {
				//you lose
			}
			//delete enemys[i]
		}
		for (int j = 0; j < fireBalls.size(); j++) {//move all fireBalls
			if (enemys[i]->checkFireballCollison(*fireBalls[j])) {

				//delete fireBalls[i];
				//delete enemys[i];
			}
			//if ()
		}
		
	}
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i]->checkPlayerCollison(*player)) {
			player->gotLog();
			logs[i]->respawnLog();
		}
		

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

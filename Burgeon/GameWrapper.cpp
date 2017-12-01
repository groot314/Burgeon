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

	for (int i = 0; i < fireBalls.size(); i++) { //move all fireBalls
		fireBalls[i]->movement();
		
		if (fireBalls[i]->isOutOfBounds()) {

			FireBall *tempFire1 = fireBalls[i];
			fireBalls.erase(fireBalls.begin() + i);
			delete tempFire1;
		}
	}
	for (int i = 0; i < heatSeekers.size(); i++) {
		heatSeekers[i]->movement(*player);

		if (heatSeekers[i]->checkPlayerCollision(*player)) {
			if (!player->isTooSmall()) {
				player->isHit();
			}
			else {
				//you lose
			}
			heatSeekingEnemy *tempEnemy2 = heatSeekers[i];
			heatSeekers.erase(heatSeekers.begin() + i);
			delete tempEnemy2;

			heatSeekingEnemy *newEnemy = new heatSeekingEnemy(window);
			heatSeekers.push_back(newEnemy);
		}
		for (int j = 0; j < fireBalls.size(); j++) {//move all fireBalls
			if (heatSeekers[i]->checkFireballCollison(*fireBalls[j])) {
				FireBall *tempFire = fireBalls[j];
				heatSeekingEnemy *tempEnemy = heatSeekers[i];

				fireBalls.erase(fireBalls.begin() + j);
				delete tempFire;

				heatSeekers.erase(heatSeekers.begin() + i);
				delete tempEnemy;

				heatSeekingEnemy *newEnemy = new heatSeekingEnemy(window);
				heatSeekers.push_back(newEnemy);
			}
		}

		if (heatSeekers[i]->isOutOfBounds()) {
			heatSeekingEnemy *tempEnemy3 = heatSeekers[i];
			heatSeekers.erase(heatSeekers.begin() + i);
			delete tempEnemy3;

			heatSeekingEnemy *newEnemy = new heatSeekingEnemy(window);
			heatSeekers.push_back(newEnemy);
		}
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
			Enemy *tempEnemy2 = enemys[i];
			enemys.erase(enemys.begin() + i);
			delete tempEnemy2;

			Enemy *newEnemy = new Enemy(window);
			enemys.push_back(newEnemy);
		}
		for (int j = 0; j < fireBalls.size(); j++) {//move all fireBalls
			if (enemys[i]->checkFireballCollison(*fireBalls[j])) {
				FireBall *tempFire = fireBalls[j];
				Enemy *tempEnemy = enemys[i];

				fireBalls.erase(fireBalls.begin() + j);
				delete tempFire;

				enemys.erase(enemys.begin() + i);
				delete tempEnemy;

				Enemy *newEnemy = new Enemy(window);
				enemys.push_back(newEnemy);
			}		
		}
		
		if (enemys[i]->isOutOfBounds()) {
			Enemy *tempEnemy3 = enemys[i];
			enemys.erase(enemys.begin() + i);
			delete tempEnemy3;

			Enemy *newEnemy = new Enemy(window);
			enemys.push_back(newEnemy);
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
	for (int i = 0; i < heatSeekers.size(); i++) {//draw all enemeys
		window.draw(*heatSeekers[i]);
	}
	window.display();
}

GameWrapper::~GameWrapper()
{
}

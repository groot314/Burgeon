#include "GameWrapper.h"

void GameWrapper::update(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();


	}

	//
	//Player updates
	player->controlMovement(window);
	if (!player->isTooSmall()) {
		player->controlShoot(event, fireBalls);
	}


	//
	//FireBall updates
	for (int i = 0; i < fireBalls.size(); i++) {
		fireBalls[i]->movement();
		
		if (fireBalls[i]->isOutOfBounds()) {

			FireBall *tempFire1 = fireBalls[i];
			fireBalls.erase(fireBalls.begin() + i);
			delete tempFire1;
		}
	}
	
	//
	//Enemy updates
	for (int i = 0; i < enemys.size(); i++) {

		if (enemys[i] == (dynamic_cast <heatSeekingEnemy *>(enemys[i]))) {//is a heatseeker enemy
			(dynamic_cast <heatSeekingEnemy *>(enemys[i]))->movement(*player);
		}
		else {//regular enemy
			enemys[i]->movement();
		}

		if (enemys[i]->checkPlayerCollision(*player)) {
			if (!player->isTooSmall()) {
				player->isHit();
			}
			else {
				//you lose
			}
			deleteEnemy(window, enemys[i], i);
			deathCount++;
		}
		for (int j = 0; j < fireBalls.size(); j++) {
			if (enemys[i]->checkFireballCollison(*fireBalls[j])) {
				FireBall *tempFire = fireBalls[j];
				fireBalls.erase(fireBalls.begin() + j);
				delete tempFire;

				deleteEnemy(window, enemys[i], i);
				deathCount++;
			}		
		}
		
		if (enemys[i]->isOutOfBounds()) {
			deleteEnemy(window, enemys[i], i);
			deathCount++;
		}
		
	}

	//
	//Log updates
	for (int i = 0; i < logs.size(); i++) {
		if (logs[i]->checkPlayerCollison(*player)) {
			player->gotLog();
			logs[i]->respawnLog();

			int chance;
			chance = rand() % 100;

			if (chance <= 50 && deathCount < 10) {
				std::cout << "DeathCount:" << deathCount << std::endl;
				Enemy *newEnemy = new Enemy(window);
				enemys.push_back(newEnemy);

			}
			else if (chance <= 70 && deathCount < 15) {
				std::cout << "DeathCount:" << deathCount << std::endl;

				Enemy *newEnemy = new Enemy(window);
				enemys.push_back(newEnemy);
			}
			else if (deathCount >= 15) {
				std::cout << "DeathCount:" << deathCount << std::endl;

				Enemy *newEnemy = new Enemy(window);
				enemys.push_back(newEnemy);

				if (chance <= 20) {
					heatSeekingEnemy *newEnemy = new heatSeekingEnemy(window);
					enemys.push_back(newEnemy);
				}
			}
		}
		

	}
}

void GameWrapper::render(sf::RenderWindow & window)
{
	window.clear();

	sprite.setScale(sf::Vector2f(.6666, .6666));
	window.draw(sprite);

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

void GameWrapper::deleteEnemy(sf::RenderWindow &window, Enemy *deletion, int i)//i = array value to delete
{
	if (deletion == (dynamic_cast <heatSeekingEnemy *>(enemys[i]))) {//is a heatseeker enemy
		Enemy *tempEnemy = deletion;
		enemys.erase(enemys.begin() + i);

		int chance;
		chance = rand() % 100;
		if (chance <= 95) {
			heatSeekingEnemy *newEnemy = new heatSeekingEnemy(window);
			enemys.push_back(newEnemy);
		}

		delete tempEnemy;//delete object
	}
	else {//regular enemy
		Enemy *tempEnemy = deletion;
		enemys.erase(enemys.begin() + i);

		//Enemy *newEnemy = new Enemy(window);
		//enemys.push_back(newEnemy);

		delete tempEnemy;//delete object
	}
}

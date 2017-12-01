#include <SFML/Graphics.hpp>
#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Fireball.h"
#include "Log.h"
#include "heatSeekingEnemy.h"

class GameWrapper {

public:
	GameWrapper(sf::RenderWindow &window) {
		Player *playerP = new Player(window, { 300,300 });//init player
		player = playerP;

		for (int i = 0; i < 3; i++) {
			Log *newLog = new Log(window);
			logs.push_back(newLog);
		}

		for (int i = 0; i < 3; i++) {
			Enemy *newEnemy = new Enemy(window);
			enemys.push_back(newEnemy);
		}

		for (int i = 0; i < 1; i++) {
			heatSeekingEnemy *newHeatSeeker = new heatSeekingEnemy(window);
			heatSeekers.push_back(newHeatSeeker);

		}
	}

	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);

	~GameWrapper();

private:
	Player *player;
	std::vector<Log*> logs;
	std::vector<FireBall*> fireBalls;
	std::vector<Enemy*> enemys;
	std::vector<heatSeekingEnemy*> heatSeekers;
};
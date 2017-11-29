#include <SFML/Graphics.hpp>
#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Fireball.h"
#include "Log.h"

class GameWrapper {

public:
	GameWrapper(sf::RenderWindow &window) {
		Player *playerP = new Player(window, { 300,300 });//init player
		player = playerP;

		Log *newLog = new Log(window);
		logs.push_back(newLog);

		Enemy *newEnemy = new Enemy(window);
		enemys.push_back(newEnemy);
	}

	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);

	~GameWrapper();

private:
	Player *player;
	std::vector<Log*> logs;
	std::vector<FireBall*> fireBalls;
	std::vector<Enemy*> enemys;
};
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
		sprite = sf::Sprite(getBackground());
		

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
			enemys.push_back(newHeatSeeker);

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
	int deathCount = 0;

	void deleteEnemy(sf::RenderWindow &window, Enemy *deletion, int i);

	sf::Sprite sprite;

	static sf::Sprite getBackground() {
		static sf::Sprite s;

		static sf::Texture texture;
		if (!texture.loadFromFile("background2.png")) {
			std::cout << "Texture not loaded" << std::endl;
		}
		texture.setSmooth(true);
		s.setTexture(texture);

		return s;
	}
};
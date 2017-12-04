#include <SFML/Graphics.hpp>
#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Fireball.h"  
#include "Log.h"
#include "heatSeekingEnemy.h"
#include "HealthAndScore.h"


class GameWrapper {

public:
	GameWrapper(sf::RenderWindow &window) {
		gameOver = false;

		sprite = sf::Sprite(getBackground());
		score = new HealthAndScore({ 75,10 });
		health = new Health({ 1120, 10 });

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
	bool isGameOver();

	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);

	int getScore();

	~GameWrapper();

private:
	bool gameOver;

	Player *player;
	std::vector<Log*> logs;
	std::vector<FireBall*> fireBalls;
	std::vector<Enemy*> enemys;
	int deathCount = 0;
	int heatCount = 0;
	int timeCounter = 0;
	int sec = 2;
	HealthAndScore *score;
	Health *health;


	void timeSpawn(int timeCounter, int min, int max, sf::RenderWindow &window, bool heatSeeker);
	void logChanceSpawn(int deathCount, sf::RenderWindow &window, bool heatSeeker);
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
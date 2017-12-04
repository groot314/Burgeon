#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class HealthAndScore : public sf::Text {

public:

	HealthAndScore(sf::Vector2f pos, int score = 0) {

		if (!font.loadFromFile("LeagueGothic.otf"))
		{
			// doesn't load
			std::cout << "LeagueGothic failed";
		
		}

		else {

			this->setFont(font);
			this->setCharacterSize(32);
			this->setColor(sf::Color::Black);
			this->setScore(score);
			this->setPosition(pos);
		}
	}

	int getScore() {

		return score;
	}

	void setScore(int newScore) {

		std::string string;
		score = newScore;
		string = "Score: ";
		string.append(std::to_string(score));
		this->setString(string);
	}

private:

	int score;
	sf::Font font;
};

class Health : public sf::Text {

public:

	Health(sf::Vector2f pos, int health = 70) {

		if (!font.loadFromFile("LeagueGothic.otf"))
		{
			// doesn't load
			std::cout << "LeagueGothic failed";

		}

		else {

			this->setFont(font);
			this->setCharacterSize(32);
			this->setColor(sf::Color::Black);
			this->setHealth(health);
			this->setPosition(pos);

		}
	}

	int getHealth() {

		return health;
	}

	void setHealth(int newHealth) {

		std::string string;
		health = newHealth;
		string = "Health: ";
		string.append(std::to_string(health));
		this->setString(string);
	}

private:

	int health;
	sf::Font font;
};
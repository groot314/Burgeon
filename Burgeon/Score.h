#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

class Score : public sf::Text {

public:

	Score(sf::Vector2f pos, int score = 0) {

		if (!font.loadFromFile("arial.ttf"))
		{
			// doesn't load
			std::cout << "Arial fai led";
		
		}

		else {

			this->setFont(font);
			this->setCharacterSize(24);
			this->setColor(sf::Color::Red);
			this->setScore(score);

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
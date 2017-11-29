#pragma once
#include <SFML\Graphics.hpp>

class Player : public sf::CircleShape {

public:
	Player(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error"), sf::Vector2f pos = { 0,0 });

	void control();

	void isHit();
	void gotLog();
	void shot();

private:

};
#include <SFML\Graphics.hpp>

class Enemy : public sf::CircleShape {
	
public:
	Enemy(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error"), sf::Vector2f pos = { 0,0 }) :CircleShape(15) {
		this->setPosition(pos);
		this->setFillColor(sf::Color::Blue);
	}

private:

};
#include <SFML\Graphics.hpp>

class FireBall : public sf::CircleShape {

public:
	FireBall(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error"), sf::Vector2f pos = { 0,0 }) :CircleShape(10) {
		this->setPosition(pos);
		this->setFillColor(sf::Color::Red);
	}

private:

};

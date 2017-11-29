#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Fireball.h"

class Enemy : public sf::CircleShape {
	
public:

	Enemy(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error")) :CircleShape(15);

	void movement();
	bool checkPlayerCollision(Player &player);
	bool checkFireballCollison(FireBall &fireball);

private:

	int xMovement;
	int yMovement;
};
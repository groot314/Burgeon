#include <SFML/Graphics.hpp>
#include "Player.h"

class GameWrapper {

public:
	GameWrapper(sf::RenderWindow &window) {
		player = Player(window, { 300,300 });//init player
	}

	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);

	~GameWrapper();

private:
	Player player;
};
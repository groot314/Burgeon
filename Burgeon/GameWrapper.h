#include <SFML/Graphics.hpp>

class GameWrapper {

public:
	GameWrapper();

	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);

	~GameWrapper();

private:
	
};
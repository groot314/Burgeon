#include <SFML/Graphics.hpp>
#include "GameWrapper.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(750, 750), "Burgeon");
	
	GameWrapper gw;

	while (window.isOpen())
	{
		
		gw.update(window);

		gw.render(window);
		
	}

	return(0);
}
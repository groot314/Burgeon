#include <SFML/Graphics.hpp>
#include "GameWrapper.h"

int main(void)
{
	srand(time(NULL));//random

	sf::RenderWindow window(sf::VideoMode(750, 750), "Burgeon");
	
	GameWrapper gw(window);

	while (window.isOpen())
	{
		
		gw.update(window);

		gw.render(window);
		
	}

	return(0);
}
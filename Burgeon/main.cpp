#include <SFML/Graphics.hpp>

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(750, 750), "Burgeon");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//draw objects
		window.display();
	}

	return(0);
}
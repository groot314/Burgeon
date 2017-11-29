#include <SFML\Graphics.hpp>

class FireBall : public sf::CircleShape {

public:
	FireBall(sf::RenderWindow &window = sf::RenderWindow(sf::VideoMode(500, 500), "Error"), sf::Vector2f pos = { 0,0 }, int shootDirection=-2, int speed=.050 ) :CircleShape(10) {
		this->setPosition(pos);
		this->setFillColor(sf::Color::Red);
		this->setRadius(20);
		this->speed = speed;
	}

	void setSpeed(int newSpeed)
	{
		speed = newSpeed;
	}

	void movement()
	{
		this->move(xMovement*speed, yMovement*speed);
	}
	
	

private:
	int speed;
	int xMovement;
	int yMovement;

	int shootDirection(int direction)
	{
		if (direction == 1)//move up
		{
			this->xMovement = 0;
			this->yMovement = -1;
		}
		else if (direction == 2)//move left
		{
			this->xMovement = -1;
			this->yMovement = 0;
		}
		else if (direction == 3)//move right
		{
			this->xMovement = 1;
			this->yMovement = 0;
		}
		else if (direction == 4)//move down
		{
			this->xMovement = 0;
			this->yMovement = 1;
		}
	}
};

#pragma once
#include <SFML\Graphics.hpp>

class FireBall : public sf::CircleShape {

public:
	FireBall(sf::Vector2f pos = { 0,0 }, int shootDirection=-2, double speed=.050 ) :CircleShape(10) {
		this->setPosition(pos);
		this->setFillColor(sf::Color::Red);
		this->speed = speed;
		this->shootDirection(shootDirection);
	}

	void setSpeed(double newSpeed)
	{
		speed = newSpeed;
	}

	void movement()
	{
		this->move(xMovement*speed, yMovement*speed);
	}
	
	

private:
	double speed;
	int xMovement;
	int yMovement;

	void shootDirection(int direction)
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

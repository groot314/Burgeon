#pragma once
#include <SFML\Graphics.hpp>

class FireBall : public sf::Sprite {

public:
	FireBall(sf::Vector2f windowSize, sf::Vector2f pos = { 0,0 }, int shootDirection = -2, double speed = 2) :Sprite(getSprite()) {
		this->windowSize = windowSize;

		this->speed = speed;
		this->shootDirection(shootDirection,pos);
	}

	void setSpeed(double newSpeed)
	{
		speed = newSpeed;
	}

	void movement()
	{
		this->move(xMovement*speed, yMovement*speed);
	}

	bool isOutOfBounds()
	{
		if (this->getPosition().x > windowSize.x) {
			return true;
		}
		if (this->getPosition().y > windowSize.y) {
			return true;
		}
		if (this->getPosition().x < -this->getTextureRect().width) {
			return true;
		}
		if (this->getPosition().y < -this->getTextureRect().height) {
			return true;
		}

		return false;
	}
	
	

private:
	sf::Vector2f windowSize;

	double speed;
	int xMovement;
	int yMovement;

	void shootDirection(int direction, sf::Vector2f pos)
	{
		if (direction == 1)//move up
		{
			this->setPosition({ pos.x - (this->getTextureRect().height / 2), pos.y - (this->getTextureRect().width / 2) });
			this->xMovement = 0;
			this->yMovement = -1;
			this->setRotation(270);
		}
		else if (direction == 2)//move left
		{
			this->setPosition({ pos.x + (this->getTextureRect().width / 2), pos.y + (this->getTextureRect().height / 2) });
			this->xMovement = -1;
			this->yMovement = 0;
			this->setRotation(180);
		}
		else if (direction == 3)//move right
		{
			this->setPosition({ pos.x - (this->getTextureRect().width / 2), pos.y - (this->getTextureRect().height / 2) });
			this->xMovement = 1;
			this->yMovement = 0;
			this->setRotation(0);
		}
		else if (direction == 4)//move down
		{
			this->setPosition({ pos.x + (this->getTextureRect().height / 2), pos.y + (this->getTextureRect().width / 2) });
			this->xMovement = 0;
			this->yMovement = 1;
			this->setRotation(90);
		}
	}

	static sf::Sprite getSprite() {
		static sf::Sprite s;

		static sf::Texture texture;
		if (!texture.loadFromFile("fireball.png")) {
			std::cout << "Texture not loaded" << std::endl;
		}
		texture.setSmooth(true);
		s.setTexture(texture);

		return s;
	}
};

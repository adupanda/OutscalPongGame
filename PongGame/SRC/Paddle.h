#pragma once

#include "SFML/Graphics.hpp"

class Paddle
{
private:

	//Shape Position and speed
	sf::RectangleShape m_Shape;
	sf::Vector2f m_Position;
	
	float m_Speed = 1100;

	bool m_MovingUp = false;

	bool m_MovingDown = false;

	float m_windowSizeX;

	float m_windowSizeY;
	
public:

	Paddle(float startX, float startY, float windowSizeX, float windowSizeY);


	sf::RectangleShape getShape();

	sf::FloatRect getPosition();

	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();

	void Update(sf::Time deltaTime);

};


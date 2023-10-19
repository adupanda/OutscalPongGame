#include "Ball.h"
#include <iostream>



Ball::Ball(float startX,float startY,float windowSizeX,float windowSizeY)
{
	//Setting Initial values for variables
	m_Position.x = startX;

	m_Position.y = startY;

	m_BallShape.setSize(sf::Vector2f(10, 10));
	
	m_BallShape.setPosition(m_Position);

	m_WindowSizeX = windowSizeX;

	m_WindowSizeY = windowSizeY;

	if (!buffer.loadFromFile("SRC/Audio/BallBouncing.mp3"))
	{
		std::cout << "Sound not found";
	}

	bounceSound.setBuffer(buffer);
	
}


sf::FloatRect Ball::getPosition()
{
	return m_BallShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return m_BallShape;
}

void Ball::missSides()
{
	//Hardcoded values for window size and ball needs to spawn in center of window
	m_Position.x = m_WindowSizeX / 2;
	m_Position.y = m_WindowSizeY / 2;
}


void Ball::BounceWalls()
{
	m_DirectionY = -m_DirectionY;
	bounceSound.play();
}

void Ball::hitBall()
{
	m_DirectionX = -m_DirectionX;
	bounceSound.play();
}

void Ball::Update(sf::Time deltaTime)
{
	m_Position.x += m_DirectionX * m_Speed * deltaTime.asSeconds();

	m_Position.y += m_DirectionY * m_Speed * deltaTime.asSeconds();

	m_BallShape.setPosition(m_Position);
}


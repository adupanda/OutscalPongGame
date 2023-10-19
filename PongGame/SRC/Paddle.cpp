#include "Paddle.h"

Paddle::Paddle(float startX, float startY, float windowSizeX, float windowSizeY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(5, 50));

	m_Shape.setFillColor(sf::Color::Red);
	m_Shape.setOutlineColor(sf::Color::White);
	m_Shape.setOutlineThickness(3);

	m_Shape.setPosition(m_Position);

	windowSizeX = m_windowSizeX;
	windowSizeY = m_windowSizeY;
}

sf::RectangleShape Paddle::getShape()
{
	return m_Shape;
}

sf::FloatRect Paddle::getPosition()
{
	return m_Shape.getGlobalBounds();
}

void Paddle::moveUp()
{
	m_MovingUp = true; 
}

void Paddle::moveDown()
{
	m_MovingDown = true;
}

void Paddle::stopUp()
{
	m_MovingUp = false;
}

void Paddle::stopDown()
{
	m_MovingDown = false;
}

void Paddle::Update(sf::Time deltaTime)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * deltaTime.asSeconds();
	}
	if (m_MovingDown)
	{
		m_Position.y += m_Speed * deltaTime.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}


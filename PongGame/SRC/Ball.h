#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Ball
{

private:
	
	//Ball Position and Shape variables
	sf::Vector2f m_Position;
	sf::RectangleShape m_BallShape;

	//Ball Movement Variables
	float m_Speed = 500;
	float m_DirectionX = 1.0f;
	float m_DirectionY = 1.0f;

	//Size Of Game window passed in as a parameter
	float m_WindowSizeX = 0;
	float m_WindowSizeY = 0;

	sf::SoundBuffer buffer;
	sf::Sound bounceSound;

public:
	//Ball constructor
	Ball(float startX,float startY, float windowSizeX, float windowSizeY);
	
	//Gets Ball's position and shape
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();

	
	//Function for Destruction and respawning of ball on touching side walls
	void missSides();

	//Function for bouncing the ball on the walls
	void BounceWalls();

	
	void hitBall();

	//Function that calls every fram
	void Update(sf::Time deltaTime);
};


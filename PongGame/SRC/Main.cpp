#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Paddle.h"
#include <sstream>
#include "MainMenu.h"
#include "EndScreen.h"



void main()
{




	//Variables for setting window Size
	float WindowSizeX = 1280;
	float WindowSizeY = 720;


	

	//Creates a render window for our game
	sf::VideoMode VM(WindowSizeX, WindowSizeY);
	
	//Main menu render window
	sf::RenderWindow Menu(VM, "Main Menu",Style::Default);

	MainMenu mainMenu(WindowSizeX, WindowSizeY);

	//Draw background
	RectangleShape background;
	background.setSize(Vector2f(WindowSizeX, WindowSizeY));
	Texture Maintexture;
	Maintexture.loadFromFile("SRC/Texture/Background.jpg");
	background.setTexture(&Maintexture);

	

	while (Menu.isOpen())
	{
		Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Menu.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					
					sf::SoundBuffer buttonBuffer;

					if (!buttonBuffer.loadFromFile("SRC/Audio/BallBouncing.mp3"))
					{
						std::cout << "sound not found";
					}
					sf::Sound buttonSound;
					buttonSound.setBuffer(buttonBuffer);
					

					int x = mainMenu.MainMenuPressed();
					buttonSound.play();

					if(x == 0)
					{
						
						sf::RenderWindow window(VM, "PongRender");
						//Used to set deltaTime
						sf::Clock clock;
						sf::SoundBuffer buffer;
						sf::Sound BackgroundSound;

						if (!buffer.loadFromFile("SRC/Audio/BackgroundAudio.mp3"))
						{
							std::cout << "sound not found";
						}

						BackgroundSound.setBuffer(buffer);

						BackgroundSound.play();

						//EndGameBool
						bool EndGame =false;

						//Spawns ball at the center at start
						Ball gameBall(WindowSizeX / 2, WindowSizeY / 2, WindowSizeX, WindowSizeY);

						//Spawns paddle at left side
						Paddle P1Paddle(200, WindowSizeY / 2, WindowSizeX, WindowSizeY);
						//Spawns paddle at right Side
						Paddle P2Paddle(WindowSizeX - 200, WindowSizeY / 2, WindowSizeX, WindowSizeY);


						
						sf::Text P1HUD;
						sf::Text P2HUD;


						sf::Font font;
						font.loadFromFile("SRC/Fonts/PixelEmulator.otf");
						P1HUD.setFont(font);
						P1HUD.setPosition(300, 100);
						P1HUD.setCharacterSize(15);
						P1HUD.setOutlineThickness(4);
						P1HUD.setOutlineColor(sf::Color::Red);
						P1HUD.setFillColor(sf::Color::White);

						P2HUD.setFont(font);
						P2HUD.setPosition(980, 100);
						P2HUD.setCharacterSize(15);
						P2HUD.setOutlineThickness(4);
						P2HUD.setOutlineColor(sf::Color::Red);
						P2HUD.setFillColor(sf::Color::White);

						int P1Score = 0;
						int P2Score = 0;
						std::stringstream ssP1;
						std::stringstream ssP2;

						ssP1 << P1Score;
						P1HUD.setString(ssP1.str());

						ssP2 << P2Score;
						P2HUD.setString(ssP2.str());

						//Variable for deltatime
						sf::Time deltaTime;

						sf::Event event;

						//preventing double call of ball hitting paddle
						float bounceTimer = 0.1f;

						//Game Logic
						while (window.isOpen())
						{
							//Sets deltaTime
							deltaTime = clock.restart();
							bounceTimer -= deltaTime.asSeconds();


							if (gameBall.getPosition().intersects(P2Paddle.getPosition()))
							{
								if (bounceTimer < 0)
								{
									gameBall.hitBall();
									bounceTimer = 0.1f;
								}

							}

							if (gameBall.getPosition().intersects(P1Paddle.getPosition()))
							{
								if (bounceTimer < 0)
								{
									gameBall.hitBall();
									bounceTimer = 0.1f;
								}
							}

							//While loop to make close button function work
							while (window.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
								{
									window.close();
								}
							}

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							{
								window.close();
							}

							//Paddle movement with restrictions
							if (P1Paddle.getPosition().top < 0)
							{
								P1Paddle.stopUp();
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
								{
									P1Paddle.moveDown();
								}
								else
								{
									P1Paddle.stopDown();
								}
							}
							else if (P1Paddle.getPosition().top + P1Paddle.getPosition().height > WindowSizeY)
							{
								P1Paddle.stopDown();
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
								{
									P1Paddle.moveUp();
								}
								else
								{
									P1Paddle.stopUp();
								}

							}
							else
							{
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
								{
									P1Paddle.moveUp();
								}
								else
								{
									P1Paddle.stopUp();
								}
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
								{
									P1Paddle.moveDown();
								}
								else
								{
									P1Paddle.stopDown();
								}
							}



							if (P2Paddle.getPosition().top < 0)
							{
								P2Paddle.stopUp();
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
								{
									P2Paddle.moveDown();
								}
								else
								{
									P2Paddle.stopDown();
								}
							}
							else if (P2Paddle.getPosition().top + P2Paddle.getPosition().height > WindowSizeY)
							{
								P2Paddle.stopDown();
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
								{

									P2Paddle.moveUp();
								}
								else
								{
									P2Paddle.stopUp();
								}
							}
							else
							{
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
								{

									P2Paddle.moveUp();
								}
								else
								{
									P2Paddle.stopUp();
								}
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
								{
									P2Paddle.moveDown();
								}
								else
								{
									P2Paddle.stopDown();
								}

							}

							//Makes the ball bounce
							if (gameBall.getPosition().top < 0 || gameBall.getPosition().top + gameBall.getPosition().height>WindowSizeY)
							{
								gameBall.BounceWalls();

							}

							//Makes the ball reset position once its hit the side
							if (gameBall.getPosition().left < 0)
							{
								P2Score++;
								if (P2Score >= 5)
								{
									EndGame = true;
									window.clear();
									EndScreen endScreen(WindowSizeX, WindowSizeY, "P2 Wins");
									endScreen.DrawText(window);
									window.display();
								}
								gameBall.missSides();
								ssP2.str("");
								ssP2 << P2Score;
								P2HUD.setString(ssP2.str());
							}
							else if (gameBall.getPosition().left + gameBall.getPosition().width > WindowSizeX)
							{
								P1Score++;
								if (P1Score >= 5)
								{
									EndGame = true;
									window.clear();
									EndScreen endScreen(WindowSizeX, WindowSizeY, "P1 Wins");
									endScreen.DrawText(window);
									window.display();
								}
								gameBall.missSides();
								ssP1.str("");
								ssP1 << P1Score;
								P1HUD.setString(ssP1.str());
							}



							
							if (!EndGame)
							{
								//Calling Update functions on all game objects
								window.clear();
								gameBall.Update(deltaTime);
								P1Paddle.Update(deltaTime);
								P2Paddle.Update(deltaTime);
								//Drawing everything to the screen
								window.draw(gameBall.getShape());
								window.draw(P1Paddle.getShape());
								window.draw(P2Paddle.getShape());
								window.draw(P1HUD);
								window.draw(P2HUD);
								window.display();
							}
							

						}
						
						

					
						Menu.close();
					}
					else if (x == 1)
					{
						buttonSound.play();
						Menu.close();
					}
				}
			}
			
		}


		Menu.clear();
		Menu.draw(background);
		mainMenu.drawText(Menu);
		
		Menu.display();
		
	}


	
	

	

	

}
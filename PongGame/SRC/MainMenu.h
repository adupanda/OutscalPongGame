#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 2

class MainMenu
{

public:

	MainMenu(float width, float height);


	void drawText(RenderWindow& window);

	void MoveUp();
	void MoveDown();

	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~MainMenu();

	
	
private:

	int MainMenuSelected = 0;

	Font fontToUse;

	Text mainMenu[Max_main_menu];

	

	
};


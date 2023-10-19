#include "MainMenu.h"
#include <sstream>

MainMenu::MainMenu(float width, float height)
{
	if (!fontToUse.loadFromFile("SRC/Fonts/PixelEmulator.otf"))
	{
		cout << "No Font is found";
	}
	
	

	//Play button

	mainMenu[0].setFont(fontToUse);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	

	//Quit button

	mainMenu[1].setFont(fontToUse);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Exit");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	

}

void MainMenu::drawText(RenderWindow& window)
{
	
	for (int i = 0; i < Max_main_menu; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 1;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

void MainMenu::MoveDown()
{
	if (MainMenuSelected +1 <= Max_main_menu)
	{

		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == 2)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

MainMenu::~MainMenu()
{
}




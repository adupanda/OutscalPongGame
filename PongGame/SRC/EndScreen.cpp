#include "EndScreen.h"
#include <sstream>

EndScreen::EndScreen(float width, float height,String textToDisplay)
{
	if (!EndScreenfont.loadFromFile("SRC/Fonts/PixelEmulator.otf"))
	{
		cout << "Font not found";
	}

	EndScreenText.setFont(EndScreenfont);
	EndScreenText.setFillColor(Color::White);
	EndScreenText.setString(textToDisplay);
	EndScreenText.setCharacterSize(70);
	EndScreenText.setPosition(400, 200);
}

void EndScreen::DrawText(RenderWindow& window)
{
	window.draw(EndScreenText);
}


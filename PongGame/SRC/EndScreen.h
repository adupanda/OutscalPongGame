#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class EndScreen
{
public:

	EndScreen(float width, float height,String textToDisplay);

	void DrawText(RenderWindow& window);


private:

	Text EndScreenText;

	Font EndScreenfont;
};


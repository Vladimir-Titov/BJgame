#pragma once

#include "main.hpp"

class MyWindow: public RenderWindow
{
public:
	static const int	WIDTH = 800;
	static const int	HEIGHT = 600;

	MyWindow():
	RenderWindow(VideoMode(WIDTH, HEIGHT), "BlackJack", Style::Default) 
	{
		this->setPosition(Vector2i(510, 250));
		this->setVerticalSyncEnabled(true);
	};
};
#pragma once

#include "main.hpp"

class Game
{
private:
	int			deal_start = 0;
	int			check_winner = 0;
	int			is_deal = 0;
	int			take_money = 0;
	MyWindow	window;
	Event		event;
	Deck		deck;
	DrawImage	image;
	Player		player = Player("Vova", 5000);
	Player		casino = Player("casino", 100000);

public:
	Game() {};

	Deck&		getDeck();
	MyWindow&	getWindow();
	void		checkEvent(Event &event);
	void		dealCard();
	void		start();
	void		checkWhoWin();

	friend class DrawImage;
};
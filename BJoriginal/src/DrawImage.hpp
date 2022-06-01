#pragma once

#include "main.hpp"

class Game;

class DrawImage
{
private:
	Font	font;
	Text	pl_name_text;
	Text	pl_count_cash_text;
	Text	place_ur_bet_text;
	Text	bet_text;
	Text	who_win_text;
	Texture	cash_texture;
	Sprite	cash_sprite;
	Color	red = Color(184, 74, 50, 255);
	Color	blue = Color(11, 91, 231, 255);

	DrawImage&	drawCash(Game& game);
	DrawImage&	drawDeck(Game& game);
	DrawImage&	drawPlayer(Game& game);
	DrawImage&	drawPlaceBet(Game& game);

public:
	DrawImage() 
	{
		font.loadFromFile("font/sfns-display-bold.ttf");
		cash_texture.loadFromFile("chips/pokerchip1.png");
		cash_sprite.setTexture(cash_texture);
	};

	DrawImage&	drawHand(Game& game);
	DrawImage&	drawWinner(Game& game, Player& player);
	DrawImage&	fillWindow(Game& game);
};
#include "main.hpp"

DrawImage&	DrawImage::drawCash(Game& game)
{
	cash_sprite.setPosition(750, 40);
	game.window.draw(cash_sprite);

	pl_count_cash_text.setFont(this->font);
	pl_count_cash_text.setString(to_string(game.player.getCash()));
	pl_count_cash_text.setCharacterSize(24);
	pl_count_cash_text.setPosition(680, 37);
	pl_count_cash_text.setFillColor(red);
	game.window.draw(pl_count_cash_text);
	return (*this);
}

DrawImage&	DrawImage::drawDeck(Game& game)
{
	Sprite spr;
	spr = game.deck.getSprite();
	spr.setPosition(660, 160);
	game.window.draw(spr);
	return (*this);
}

DrawImage&	DrawImage::drawPlayer(Game& game)
{
	pl_name_text.setFont(this->font);
	pl_name_text.setString(game.player.getName());
	pl_name_text.setCharacterSize(24);
	pl_name_text.setFillColor(blue);
	pl_name_text.setPosition(688, 0);
	game.window.draw(pl_name_text);
	return (*this);
}

DrawImage&	DrawImage::drawHand(Game& game)
{

	for (int i = 0, x = 560 / game.casino.getHandSize(); i < game.casino.getHandSize(); i++, x += 100)
	{
		if (i == 0 && game.check_winner == 0)
		{
			Sprite spr_close_card;
			spr_close_card = game.deck.getSprite();
			spr_close_card.setPosition(x, 10);
			game.window.draw(spr_close_card);
			continue ;
		}
		Sprite spr;
		spr = game.casino.getHand()[i].getSprite();
		spr.setPosition(x, 10);
		game.window.draw(spr);
	}
	for (int i = 0, x = 560 / game.player.getHandSize() ; i < game.player.getHandSize(); i++, x += 100)
	{
		Sprite spr;
		spr = game.player.getHand()[i].getSprite();
		spr.setPosition(x, 390);
		game.window.draw(spr);
	}
	return (*this);
}

DrawImage&	DrawImage::drawPlaceBet(Game& game)
{
	pl_name_text.setFont(this->font);
	pl_name_text.setString("Place your bet: ");
	pl_name_text.setCharacterSize(32);
	pl_name_text.setFillColor(red);
	pl_name_text.setPosition(190, 240);
	bet_text.setFont(this->font);
	bet_text.setString(to_string(game.player.getBet()));
	bet_text.setCharacterSize(32);
	bet_text.setFillColor(red);
	bet_text.setPosition(440, 240);
	game.window.draw(bet_text);
	game.window.draw(pl_name_text);
	return (*this);
}

DrawImage&	DrawImage::drawWinner(Game& game, Player& player)
{
	string	win = "Winner: ";
	who_win_text.setFont(this->font);
	who_win_text.setString(win.append(player.getName()));
	who_win_text.setCharacterSize(38);
	who_win_text.setFillColor(red);
	who_win_text.setPosition(200, 240);
	game.window.draw(who_win_text);
	return (*this);
}

DrawImage&	DrawImage::fillWindow(Game &game)
{
	if (game.deal_start == 0 && game.check_winner == 0)
		this->drawPlaceBet(game);
	else
		this->drawHand(game);
	this->drawCash(game);
	this->drawDeck(game);
	this->drawPlayer(game);
	return (*this);
}


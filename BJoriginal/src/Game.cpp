#include "main.hpp"

Deck&	Game::getDeck()
{
	return (this->deck);
}

MyWindow&	Game::getWindow()
{
	return (this->window);
}

void	Game::checkEvent(Event &event)
{
	switch (event.type)
	{
	case Event::Closed:
		window.close();
		break;
	case Event::KeyPressed:
		switch (event.key.code)
		{
		case Keyboard::Escape:
			window.close();
			break;
		case Keyboard::Up:
			if (deal_start == 1)
				break;
			this->player.upBet();
			break;
		case Keyboard::Down:
			if (deal_start == 1)
				break;
			this->player.downBet();
			break;
		case Keyboard::Space:
			if (deal_start == 1)
				break;
			this->player.placeBet();
			this->deal_start = 1;
			break;
		case Keyboard::W:
			this->player.addToHand(this->deck.getUpperCard());
			break;
		case Keyboard::Enter:
			if (check_winner == 1)
			{
				this->player.resetHand();
				this->casino.resetHand();
				check_winner = 0;
				take_money = 0;
				break ;
			}
			check_winner = 1;
			break ;
		}
		break;
	case Event::MouseButtonPressed:
		if (event.mouseButton.button == Mouse::Left)
		{
			cout << "mouse x :" << event.mouseButton.x << endl;
			cout << "mouse y :" << event.mouseButton.y << endl;
		}
		break ;
	}
}

void	Game::dealCard()
{
	if (!is_deal)
	{
		for (int i = 0; i < 2; i++)
		{
			player.addToHand(deck.getUpperCard());
			casino.addToHand(deck.getUpperCard());
		}
		is_deal = 1;
	}
}

void	Game::start()
{
	deck.shuffleDeck();
	while (window.isOpen())
	{
		window.clear(Color(16, 141, 60, 0));
		while (window.pollEvent(event))
			checkEvent(event);
		if (deal_start == 1 && is_deal == 0)
			dealCard();
		if (check_winner == 1)
			checkWhoWin();
		image.fillWindow(*this);
		window.display();
	}
}

void	Game::checkWhoWin()
{
	int		win = 0;

	if (this->player > this->casino)
	{
		image.drawWinner(*this, this->player);
		win = 1;
	}
	else
		image.drawWinner(*this, this->casino);
	if (take_money == 0)
	{
		this->player.takeBet(win);
		take_money = 1;
	}
	deal_start = 0;
	is_deal = 0;
}
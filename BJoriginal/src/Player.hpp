#pragma once

#include "main.hpp"

class Player
{
private:
	int				m_money;
	string			m_name;
	array<Card, 8>	m_hand;
	int				m_hand_size;
	int				m_bet = 0;
	int				m_hand_value = 0;

public:
	Player(): m_money {15000}, m_name {"Vova"}, m_hand {}, m_hand_size {0} {};
	Player(string name) : m_name {name}, m_hand {}, m_hand_size {0} { m_money = 5000; };
	Player(string name, int cash ): m_name {name}, m_money {cash}, m_hand {}, m_hand_size {0} {};

	int&			getCash();
	string&			getName();
	bool			placeBet();
	Player&			addToHand(Card card);
	array<Card, 8>	getHand();
	int				getHandSize();
	Player&			plusGetSize();
	int&			getBet();
	Player&			upBet();
	Player&			downBet();
	int				getHandValue();
	void			resetHand();
	void			takeBet(int win);

	friend bool	operator> (const Player &p1, const Player &p2);
};
#include "main.hpp"

string&	Player::getName()
{
	return (m_name);
}

int& Player::getCash()
{
	return (this->m_money);
}

bool	Player::placeBet()
{
	this->m_money -= m_bet;
	return (true);
}

Player&	Player::addToHand(Card card)
{
	int	index = m_hand_size;
	m_hand[index] = card;
	m_hand_size++;
	m_hand_value += card.getCardValue();
	return (*this);
}

array<Card, 8>	Player::getHand()
{
	return (this->m_hand);
}

int	Player::getHandSize()
{
	return (this->m_hand_size);
}

Player&	Player::plusGetSize()
{
	this->m_hand_size++;
	return (*this);
}

int&	Player::getBet()
{
	return (this->m_bet);
}

Player&	Player::upBet()
{
	m_bet += 100;
	assert(m_bet < m_money);
	return (*this);
}

Player&	Player::downBet()
{
	m_bet -= 100;
	assert(m_bet >= 0);
	return (*this);
}

int	Player::getHandValue()
{
	int value = 0;
	for(auto &var : m_hand)
	{
		value += var.getCardValue();
	}
	return (value);
}

void	Player::resetHand()
{
	memset(&this->m_hand, 0, this->m_hand_size);
	m_hand_size = 0;
}

void	Player::takeBet(int win)
{
	if (win)
		m_money += (m_bet * 2);
	m_bet = 0;
}

bool	operator> (const Player &p1, const Player &p2)
{
	return ((p1.m_hand_value > p2.m_hand_value) && (p1.m_hand_value <= 21));
}

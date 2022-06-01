#pragma once
#include "main.hpp"

class Deck
{
private:
	array<Card, 52>	m_deck;
	int				m_size;
	Texture			m_texture;
	Sprite			m_sprite;
	static int	getRandomNumber(int min, int max);
	static void	swapCard(Card &a, Card &b);

public:
	Deck();
	
	Deck&			shuffleDeck();
	array<Card, 52>	getDeck();
	Card&			getCard(int number);
	bool			setTexture();
	Deck&			setSprite();
	Sprite			getSprite();
	int				getSize();
	Deck&			setSize(int size);
	Card&			getUpperCard();
};
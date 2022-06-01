#pragma once
#include "main.hpp"

class Card
{
public:
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANK
	};

	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

private:
	CardRank	m_rank;
	CardSuit	m_suit;
	Texture		m_texture;
	Sprite		m_sprite;

public:
	Card();
	Card(CardRank rank, CardSuit suit): m_rank {rank}, m_suit {suit} 
	{ 
		m_texture = {}; 
		m_sprite = {};
	};

	int		getCardValue();
	bool	setTexture();
	Card&	setSprite();
	Sprite	getSprite();
};
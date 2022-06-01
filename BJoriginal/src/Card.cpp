#include "main.hpp"

Card::Card() {};

int	Card::getCardValue()
{
	switch (this->m_rank)
	{
	case RANK_2: return (2);
	case RANK_3: return (3);
	case RANK_4: return (4);
	case RANK_5: return (5);
	case RANK_6: return (6);
	case RANK_7: return (7);
	case RANK_8: return (8);
	case RANK_9: return (9);
	case RANK_10: return (10);
	case RANK_JACK: return (10);
	case RANK_QUEEN: return (10);
	case RANK_ACE: return (11);
	}
	return (0);
}

static string getPath(Card::CardRank rank, Card::CardSuit suit)
{
	string	path;

	switch (suit)
	{
	case Card::SUIT_CLUB: path.append("c"); break ;
	case Card::SUIT_DIAMOND: path.append("d"); break ;
	case Card::SUIT_HEART: path.append("h"); break ;
	case Card::SUIT_SPADE: path.append("s"); break ;
	}

	switch (rank)
	{
	case Card::RANK_2: path.append("2"); break;
	case Card::RANK_3: path.append("3"); break;
	case Card::RANK_4: path.append("4"); break;
	case Card::RANK_5: path.append("5"); break;
	case Card::RANK_6: path.append("6"); break;
	case Card::RANK_7: path.append("7"); break;
	case Card::RANK_8: path.append("8"); break;
	case Card::RANK_9: path.append("9"); break;
	case Card::RANK_10: path.append("10"); break;
	case Card::RANK_JACK: path.append("j"); break;
	case Card::RANK_KING: path.append("q"); break;
	case Card::RANK_QUEEN: path.append("k"); break;
	case Card::RANK_ACE: path.append("a"); break;
	}

	return (path);
}

bool	Card::setTexture()
{
	string	path = "sprites/card_a_";

	path.append(getPath(this->m_rank, this->m_suit));
	path.append(".png");
	return (m_texture.loadFromFile(path));
}

Card&	Card::setSprite()
{
	m_sprite.setTexture(m_texture);
	return (*this);
}

Sprite	Card::getSprite()
{
	return (this->m_sprite);
}
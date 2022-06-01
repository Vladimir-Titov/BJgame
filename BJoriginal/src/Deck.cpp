#include "main.hpp"

Deck::Deck()
{
	int	card = 0;
	for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
		for (int rank = 0; rank < Card::MAX_RANK; ++rank)
		{
			m_deck[card] = Card(static_cast<Card::CardRank>(rank),
								static_cast<Card::CardSuit>(suit));
			m_deck[card].setTexture();
			m_deck[card].setSprite();
			++card;
		}
	this->setTexture();
	this->setSprite();
	m_size = 51;
}

int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::swapCard(Card &a, Card &b)
{
	Card	tmp = a;

	a = b;
	b = tmp;
}

Deck& Deck::shuffleDeck()
{
	for (int i = 0; i < 52; i++)
	{
		int swapIndex = getRandomNumber(0, 51);
		swapCard(m_deck[i], m_deck[swapIndex]);
	}
	return *this;
}

array<Card, 52> Deck::getDeck()
{
	return (this->m_deck);
}

Card& Deck::getCard(int number)
{
	return (this->m_deck[number]);
}

bool	Deck::setTexture()
{
	return (m_texture.loadFromFile("sprites/deck_3.png"));
}

Deck&	Deck::setSprite()
{
	m_sprite.setTexture(m_texture);
	return (*this);
}

Sprite	Deck::getSprite()
{
	return (this->m_sprite);
}

int		Deck::getSize()
{
	return (this->m_size);
}

Deck&	Deck::setSize(int size)
{
	m_size = size;
	return (*this);
}

Card&	Deck::getUpperCard()
{
	return (m_deck[this->m_size--]);
}
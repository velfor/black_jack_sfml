#pragma once
#include "card.h"
#include <vector>
#include <fstream>
class Deck {
private:
	const int deck_size = 52;
	std::vector<Card> m_deck;
	void swap(Card &, Card &);
public:
	Deck();
	void shuffle();//перетасовать колоду
	Card pop();//взять верхнюю карту
	void print_deck();//печать колоду
	
};
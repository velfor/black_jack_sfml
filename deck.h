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
	void shuffle();//������������ ������
	Card pop();//����� ������� �����
	void print_deck();//������ ������
	
};
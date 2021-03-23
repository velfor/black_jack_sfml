#pragma once
#include "card.h"
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
class Deck {
private:
	const int deck_size = 52;
	std::vector<Card*> m_deck;
public:
	Deck(sf::Image&);
	void shuffle();//������������ ������
	Card pop();//����� ������� �����
	void print_deck();//������ ������
	Card getCard(int);//������� ����� �� ������
	
};
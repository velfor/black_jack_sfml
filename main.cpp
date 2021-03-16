#include <iostream>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include <SFML/Graphics.hpp>
using namespace std;
int main() {
	Game my_game;
	

	char choise;
	do {
		my_game.play();
		std::cout << "do yo want another game?" << std::endl;
		std::cout << " (enter your choice, y - yes, n - no) ";
		cin >> choise;
	   } 
		while (choise == 'y');
	   std::cout << "player wins:" << my_game.get_m_playerWon() << std::endl;
	   std::cout << "dealer wins:" << my_game.get_m_dealerWon() << std::endl;
	   std::cout << "draws:" << my_game.get_m_draw() << std::endl;
	}

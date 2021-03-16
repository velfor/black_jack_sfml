#include <iostream>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
	Game my_game;
	char choise;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works!");
	Card card1(CARD_K,CARD_DIAMONDS);
	
	while (window.isOpen())
	{
		
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == sf::Event::Closed)
				// тогда закрываем его
				window.close();
		}
		/*do {
			
			my_game.play(window);
			std::cout << "do yo want another game?" << std::endl;
			std::cout << " (enter your choice, y - yes, n - no) ";
			cin >> choise;
		} while (choise == 'y');
		std::cout << "player wins:" << my_game.get_m_playerWon() << std::endl;
		std::cout << "dealer wins:" << my_game.get_m_dealerWon() << std::endl;
		std::cout << "draws:" << my_game.get_m_draw() << std::endl;*/
		window.clear(Color(250, 220, 100, 0));
		window.draw(card1.getSprite());
		window.display();
	}
}

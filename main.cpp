#include <iostream>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include <SFML/Graphics.hpp>
using namespace sf;
void drawPlayerHand(Player&, RenderWindow*);

int main() {
	RenderWindow* window = new RenderWindow(sf::VideoMode(1024, 800), "SFML Works!");
	Image image;
	image.loadFromFile("images/deck.png");
	//Game my_game;
	//char choise;
	window->clear(Color(250, 220, 100, 0));
	while (window->isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window->pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == sf::Event::Closed)
				// тогда закрываем его
				window->close();
		}
		Deck my_deck(image);//создаем колоду
		my_deck.shuffle();//тусуем колоду
		Player player1;//создаем игрока
		Dealer dealer;//создаем дилера
		Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
		char choice = 'y';
		std::cout << std::endl;
		std::cout << "YOUR MOVE";
		std::cout << std::endl;
		while (choice != 'n') {
			//взять карту из колоды в руку
			player1.takeOneCard(my_deck);
			//печатаем руку
			player1.printHand();
			player1.drawHand();
			window->clear(Color(250, 220, 100, 0));
			drawPlayerHand(player1, window);
			window->display();
			//выводим счет и просим пользователя принять решение
			//о ходе игры (продолжить или нет)

			std::cout << "Your score is " << player1.calculateScore() << std::endl;
			if (player1.calculateScore() >= 21) break;
			std::cout << "Do you want another card?";
			std::cout << " (enter your choice, y - yes, n - no) ";
			//считываем выбор пользователя
			std::cin >> choice;
		}
		currentGameStatus = player1.checkGameStatus();
		//проверяем как сыграл игрок
		//набрал 21 - выиграл сразу
		if (currentGameStatus == Hand::GAME_WIN) {
			std::cout << "Player1 win!" << std::endl;
			//increase_playerWon();
			//return 0;
		}
		else
			//перебор - срызу проиграл
			if (currentGameStatus == Hand::GAME_LOSE) {
				std::cout << "Player1 lose!" << std::endl;
				//increase_dealerWon();
				//return 0;
			}
			else
				//игрок набрал меньше 21 очка, играет дилер
				if (currentGameStatus == Hand::GAME_CONTINUE) {
					//дилер набирает карты в руку

					dealer.play(my_deck);

					currentGameStatus = dealer.checkGameStatus();
					//проверяем, как сыграл дилер
					//если дилер набрал от 17 до 20 очков
					if (currentGameStatus == Hand::GAME_CONTINUE) {
						//вычисляем очки игрока и дилера
						int playerScore = player1.calculateScore();
						int dealerSCore = dealer.calculateScore();
						//у игрока больше очков - победил игрок
						if (playerScore > dealerSCore) {
							std::cout << "Player1 win!" << std::endl;
							//increase_playerWon();
							//return 0;
						}
						//у дилера больше - победил дилер
						if (dealerSCore > playerScore) {
							std::cout << "Dealer win!" << std::endl;
							//increase_dealerWon();
							//return 0;
						}
						//поровну - ничья
						if (dealerSCore == playerScore) {
							std::cout << "Draw!" << std::endl;
							//playersdraw();
							//return 0;
						}
					}
					else
						//у дилера 21 очков - сразу выигрыш
						if (currentGameStatus == Hand::GAME_WIN) {
							std::cout << "Dealer win!" << std::endl;
							//increase_dealerWon();
							//return 0;
						}
						else
							//у дилера перебор - сразу проигрыш
							if (currentGameStatus == Hand::GAME_LOSE) {
								std::cout << "Dealer lose!" << std::endl;
								//increase_playerWon();
								//return 0;
							}
				}
		
		//(*window).draw(dealer);
		
	}
}
void drawPlayerHand(Player& player, RenderWindow* window) {
	player.drawHand();
	int size = player.getHand().size();
	for (int i = 0; i < size; i++) {
		window->draw(player.getHand()[i]->getSprite());
	}
	
}

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
		// ������������ ������� ������� � �����
		Event event;
		while (window->pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == sf::Event::Closed)
				// ����� ��������� ���
				window->close();
		}
		Deck my_deck(image);//������� ������
		my_deck.shuffle();//������ ������
		Player player1;//������� ������
		Dealer dealer;//������� ������
		Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
		char choice = 'y';
		std::cout << std::endl;
		std::cout << "YOUR MOVE";
		std::cout << std::endl;
		while (choice != 'n') {
			//����� ����� �� ������ � ����
			player1.takeOneCard(my_deck);
			//�������� ����
			player1.printHand();
			player1.drawHand();
			window->clear(Color(250, 220, 100, 0));
			drawPlayerHand(player1, window);
			window->display();
			//������� ���� � ������ ������������ ������� �������
			//� ���� ���� (���������� ��� ���)

			std::cout << "Your score is " << player1.calculateScore() << std::endl;
			if (player1.calculateScore() >= 21) break;
			std::cout << "Do you want another card?";
			std::cout << " (enter your choice, y - yes, n - no) ";
			//��������� ����� ������������
			std::cin >> choice;
		}
		currentGameStatus = player1.checkGameStatus();
		//��������� ��� ������ �����
		//������ 21 - ������� �����
		if (currentGameStatus == Hand::GAME_WIN) {
			std::cout << "Player1 win!" << std::endl;
			//increase_playerWon();
			//return 0;
		}
		else
			//������� - ����� ��������
			if (currentGameStatus == Hand::GAME_LOSE) {
				std::cout << "Player1 lose!" << std::endl;
				//increase_dealerWon();
				//return 0;
			}
			else
				//����� ������ ������ 21 ����, ������ �����
				if (currentGameStatus == Hand::GAME_CONTINUE) {
					//����� �������� ����� � ����

					dealer.play(my_deck);

					currentGameStatus = dealer.checkGameStatus();
					//���������, ��� ������ �����
					//���� ����� ������ �� 17 �� 20 �����
					if (currentGameStatus == Hand::GAME_CONTINUE) {
						//��������� ���� ������ � ������
						int playerScore = player1.calculateScore();
						int dealerSCore = dealer.calculateScore();
						//� ������ ������ ����� - ������� �����
						if (playerScore > dealerSCore) {
							std::cout << "Player1 win!" << std::endl;
							//increase_playerWon();
							//return 0;
						}
						//� ������ ������ - ������� �����
						if (dealerSCore > playerScore) {
							std::cout << "Dealer win!" << std::endl;
							//increase_dealerWon();
							//return 0;
						}
						//������� - �����
						if (dealerSCore == playerScore) {
							std::cout << "Draw!" << std::endl;
							//playersdraw();
							//return 0;
						}
					}
					else
						//� ������ 21 ����� - ����� �������
						if (currentGameStatus == Hand::GAME_WIN) {
							std::cout << "Dealer win!" << std::endl;
							//increase_dealerWon();
							//return 0;
						}
						else
							//� ������ ������� - ����� ��������
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

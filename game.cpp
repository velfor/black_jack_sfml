#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
Game::Game() {
	m_playerWon = 0; m_dealerWon = 0; m_draw = 0;
}
int Game::get_m_playerWon() {return m_playerWon;}
int Game::get_m_dealerWon() {return m_dealerWon;}
int Game::get_m_draw() { return m_draw; }
void Game::increase_playerWon() {
	m_playerWon++;
}
void Game::increase_dealerWon() {
	m_dealerWon++;
}
void Game::playersdraw() {
	m_draw++;
}
void Game::play(sf::RenderWindow& window) {
	Deck my_deck;//������� ������
	my_deck.shuffle();//������ ������
	Player player1;//������� ������
	Dealer dealer;//������� ������
	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == sf::Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		std::cout << "player wins:" << m_playerWon << std::endl;
		std::cout << "dealer wins:" << m_dealerWon << std::endl;
		std::cout << "draws:" << m_draw << std::endl;

		player1.play(my_deck, window);

		currentGameStatus = player1.checkGameStatus();
		//��������� ��� ������ �����
		//������ 21 - ������� �����
		if (currentGameStatus == Hand::GAME_WIN) {
			std::cout << "Player1 win!" << std::endl;
			increase_playerWon();
			break;

		}
		else
			//������� - ����� ��������
			if (currentGameStatus == Hand::GAME_LOSE) {
				std::cout << "Player1 lose!" << std::endl;
				increase_dealerWon();
				break;
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
							increase_playerWon();
							break;
						}
						//� ������ ������ - ������� �����
						if (dealerSCore > playerScore) {
							std::cout << "Dealer win!" << std::endl;
							increase_dealerWon();
							break;
						}
						//������� - �����
						if (dealerSCore == playerScore) {
							std::cout << "Draw!" << std::endl;
							playersdraw();
							break;
						}
					}
					else
						//� ������ 21 ����� - ����� �������
						if (currentGameStatus == Hand::GAME_WIN) {
							std::cout << "Dealer win!" << std::endl;
							increase_dealerWon();
							break;
						}
						else
							//� ������ ������� - ����� ��������
							if (currentGameStatus == Hand::GAME_LOSE) {
								std::cout << "Dealer lose!" << std::endl;
								increase_playerWon();
								break;
							}
				}
	}
}

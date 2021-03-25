#include "player.h"
#include <iostream>
void Player::play(Deck& fDeck) {
    char choice = 'y';
    std::cout << std::endl;
    std::cout << "YOUR MOVE";
    std::cout << std::endl;
    while (choice != 'n') {
        //����� ����� �� ������ � ����
        takeOneCard(fDeck);
        //�������� ����
        printHand();
        drawHand();
        //������� ���� � ������ ������������ ������� �������
        //� ���� ���� (���������� ��� ���)

        std::cout << "Your score is " << calculateScore() << std::endl;
        if (calculateScore() >= 21) break;
        std::cout << "Do you want another card?";
        std::cout << " (enter your choice, y - yes, n - no) ";
        //��������� ����� ������������
        std::cin >> choice;
    }
}
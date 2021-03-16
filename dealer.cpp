#include "dealer.h"
#include <iostream>
void Dealer::play(Deck& fDeck){
	//����� ����� �����, ���� �� ������� 17 ����� ��� ������
	//���� ���� ������ 17
	std::cout << std::endl;
	std::cout << "DEALER MOVE";
	std::cout << std::endl;
	do {
		//����� �����
		takeOneCard(fDeck);
	} while (calculateScore() < 17);
	printHand();
	std::cout << "Dealer score is " << calculateScore() << std::endl;
}
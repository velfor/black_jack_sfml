#include "dealer.h"
#include <iostream>
void Dealer::play(Deck& fDeck){
	//дилер берет карты, пока не наберет 17 очков или больше
	//пока счет меньше 17
	std::cout << std::endl;
	std::cout << "DEALER MOVE";
	std::cout << std::endl;
	do {
		//берем карту
		takeOneCard(fDeck);
	} while (calculateScore() < 17);
	printHand();
	std::cout << "Dealer score is " << calculateScore() << std::endl;
}
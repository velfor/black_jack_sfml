#include "hand.h"
#include "card.h"
void Hand::printHand() {
	int size = m_hand.size();
	for (int i = 0; i < size; i++) m_hand[i].print_card();
}
void  Hand::takeOneCard(Deck& fDeck) {
	Card temp = fDeck.pop();
	m_hand.push_back(temp);
}
int Hand::calculateScore() {
	int size = m_hand.size();
	int score = 0;
	for (int i = 0; i < size; i++) {
		//если карта туз - то
		//попробовать добавить 10
		//иначе
		if (m_hand[i].get_rank() == Card::CardRank::CARD_A) {
			score = score + 10 + m_hand[i].get_score();
			if (score > 21) score = score - 10;
		}
		else
			score = score + m_hand[i].get_score();
	}
	return score;
}
Hand::GameStatus Hand::checkGameStatus() {
	int score = calculateScore();
	if (score < 21) return Hand::GAME_CONTINUE;
	else
		if (score == 21) return Hand::GAME_WIN;
		else return Hand::GAME_LOSE;
}
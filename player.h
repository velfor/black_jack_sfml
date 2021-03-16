#pragma once
#include "hand.h"
#include "deck.h"
class Player:public Hand {
public:
	void play(Deck&);
};
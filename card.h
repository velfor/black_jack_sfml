#pragma once
#include <iostream>
class Card
{

public:
    enum CardSuits {
        CARD_DIAMONDS,//бубны
        CARD_HEARTS,//черви
        CARD_SPADES,//пики
        CARD_CLUBS,//крести
        MAX_SUITS//конец перечисления
    };
    enum CardRank {
        CARD_2,//0
        CARD_3,//1
        CARD_4,//2
        CARD_5,//3
        CARD_6,
        CARD_7,
        CARD_8,
        CARD_9,
        CARD_10,
        CARD_J,//JACK - валет,10
        CARD_Q,//QUEEN - дама,11
        CARD_K,//KING - король,12
        CARD_A,//ACE - туз,13
        MAX_RANK//конец перечисления
    };
    Card();
    Card(CardRank, CardSuits);
    void print_card();
    int get_score();
    CardRank get_rank();
    CardSuits get_suit();
    friend std::ostream& operator<<(std::ostream& , Card&);
private:
    CardRank m_rank;
    CardSuits m_suit;

};

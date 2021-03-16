#pragma once
#include <iostream>
class Card
{

public:
    enum CardSuits {
        CARD_DIAMONDS,//�����
        CARD_HEARTS,//�����
        CARD_SPADES,//����
        CARD_CLUBS,//������
        MAX_SUITS//����� ������������
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
        CARD_J,//JACK - �����,10
        CARD_Q,//QUEEN - ����,11
        CARD_K,//KING - ������,12
        CARD_A,//ACE - ���,13
        MAX_RANK//����� ������������
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

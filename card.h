#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
enum CardSuits {
    CARD_DIAMONDS,//бубны
    CARD_HEARTS,//черви
    CARD_SPADES,//пики
    CARD_CLUBS,//крести
    MAX_SUITS//конец перечисления
};
enum CardRank {
    CARD_A,//0
    CARD_2,//1
    CARD_3,//2
    CARD_4,//3
    CARD_5,//4
    CARD_6,//5
    CARD_7,//6
    CARD_8,//7
    CARD_9,//8
    CARD_10,//9
    CARD_J,//10
    CARD_Q,//11
    CARD_K,//12
    MAX_RANK//конец перечисления
};
class Card
{
public:
    Card(sf::Image& ,CardRank, CardSuits);
    void print_card();
    int get_score();
    CardRank get_rank();
    CardSuits get_suit();
    friend std::ostream& operator<<(std::ostream& , Card&);
    sf::Sprite& getSprite();
    float getWidth() { return cardWidth; }
    float getHeight() { return cardHeight; }
    void setX(float fx) { x = fx; }
    void setY(float fy) { y = fy; }
    void drawCard();
private:
    CardRank m_rank;
    CardSuits m_suit;
    float x, y;
    static float cardWidth;
    static float cardHeight;
    sf::Texture cardTexture;
    sf::Sprite cardSprite;
};

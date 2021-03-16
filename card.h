#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
enum CardSuits {
    CARD_DIAMONDS,//�����
    CARD_HEARTS,//�����
    CARD_SPADES,//����
    CARD_CLUBS,//������
    MAX_SUITS//����� ������������
};
enum CardRank {
    CARD_A,//0
    CARD_2,//1
    CARD_3,//2
    CARD_4,//3
    CARD_5,
    CARD_6,
    CARD_7,
    CARD_8,
    CARD_9,
    CARD_10,
    CARD_J,
    CARD_Q,
    CARD_K,
    MAX_RANK//����� ������������
};
class Card
{
public:
    Card();
    Card(CardRank, CardSuits);
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
    void drawCard(sf::RenderWindow&);
private:
    CardRank m_rank;
    CardSuits m_suit;
    float x, y;
    static float cardWidth;
    static float cardHeight;
    sf::Texture cardTexture;
    sf::Image cardImage;
    sf::Sprite cardSprite;
};

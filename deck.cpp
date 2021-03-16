#include "deck.h"
#include "card.h"
#include <iostream>
#include <ctime>
Deck::Deck() {
    for (int j = 0; j < MAX_SUITS; j++) {
        for (int k = 0; k < MAX_RANK; k++) {
            //создать карту и добавить её в вектор
            m_deck.push_back(Card(static_cast<CardRank>(k), static_cast<CardSuits>(j)));
        }
    }
}
void Deck::swap(Card& a, Card& b) {
    Card temp;
    temp = a;
    a = b;
    b = temp;
}
void Deck::shuffle() {
    const int numberOfShuffles = 5;
    srand(time(0));
    for (int j = 0; j < numberOfShuffles; j++) {
        //тусуем колоду
        for (int i = 0; i < deck_size; i++) {
            //выбрали карту со случайным номером
            int randomCard = rand() % deck_size;
            //обменяли местами текущую и случайно выбранную карту
            swap(m_deck[i], m_deck[randomCard]);
        }
    }
}
void Deck::print_deck() {
    int size = m_deck.size();
    for (int i = 0; i < size; i++)
        m_deck[i].print_card();
        //std::cout << m_deck[i];
    //<< m_deck
}
Card Deck::pop() {
    int lastCard = m_deck.size() - 1;
    Card temp = m_deck[lastCard];
    m_deck.pop_back();
    return temp;
}
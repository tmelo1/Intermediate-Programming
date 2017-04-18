#ifndef _120_CARDGAME_HPP
#define _120_CARDGAME_HPP

#include <vector>
#include <algorithm>
#include <utility>

enum Suit {
    HEART, // 0
    DIAMOND, // 1
    SPADE, // 2
    CLUB // 3
};

enum Rank {
    ACE = 1,
    // 2-10 are represented by corresponding ints
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

typedef std::pair<Suit, Rank> Card;

class CardGame {
public:

    CardGame();

    Card draw_from_deck();
    Card draw_from_discard();
    void discard(Card c);

    
    // shuffle cards currently in the deck vector
    void shuffle_deck() {
        std::random_shuffle(deck.begin(), deck.end());
    }
    
    // Return number of cards currently in deck
    size_t deck_size() const { return deck.size(); }
    //                 ^^^^^
    // Do you understand why this is const?

    // Return number of cards currently in discard pile
    size_t discard_size() const { return discard_pile.size(); }
    //                    ^^^^^
    // Do you understand why this is const?
    
    // Do you understand why the other member functions
    // are not const?
    
private:

    std::vector<Card> deck;
    std::vector<Card> discard_pile;

};

#endif

#include "CardGame.hpp"

// Constructor for a CardGame - initializes instance variables
CardGame::CardGame() : deck(), discard_pile() {
    for(int suit = HEART; suit <= CLUB; suit++) {
        for(int rank = ACE; rank <= KING; rank++) {
            deck.push_back(std::make_pair((Suit)suit, (Rank)rank));
        }
    }
}


// TODO: implement this: draws the top card from the deck;
// let "back" of vector == "top" of deck.  You may assume
// the user will never try to draw from an empty deck.
Card CardGame::draw_from_deck() {
    //fill in definition
}

    
// TODO: implement this: draws the top card from the discard
// pile; let "back" of vector == "top" of pile.  You may assume
// the user will never try to draw from an empty pile.
Card CardGame::draw_from_discard() {
    //fill in definition
}

    
// TODO: implement this: place card on top of discard pile
void CardGame::discard(Card c) {
    //fill in definition
}
    

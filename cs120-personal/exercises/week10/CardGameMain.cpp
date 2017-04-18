#include <cassert>
#include <iostream>
#include "CardGame.hpp"

// TODO: *First* resolve all the TODOs in CardGame.hpp, then
// confirm that they work by building and running this program

using namespace std;

int main(){

    CardGame cg;
    assert(cg.deck_size() == 52);
    Card c1 = cg.draw_from_deck();
    Card c2 = cg.draw_from_deck();
    cg.draw_from_deck();
    assert(cg.deck_size() == 49);
    
    cg.discard(c1);
    cg.discard(c2);
    assert(cg.discard_size() == 2);
    assert(cg.draw_from_discard() == c2);
    assert(cg.draw_from_discard() == c1);

    assert(cg.discard_size() == 0);
    
    cout << "All tests passed!" << endl;
    return 0;
}

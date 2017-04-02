#include <stdio.h>
#include <stdlib.h>

// This program has a bug.  valgrind can help you find it.
//
// Hint 1: the bug is not in the is_prime function
// Hint 2: if at first valgrind says there's no bug,  try
//         increasing MAX_CANDIDATE and try again

// **********************************************
// Fix all bugs and include the corrected code in
// your end-of-class submission.
// **********************************************
// Compile with:
//    gcc -std=c99 -pedantic -Wall -Wextra -g -o primes
// to run:
//    valgrind --leak-check=full ./primes


#define MAX_CANDIDATE 50000

// return non-zero if argument is prime, otherwise return 0
int is_prime(int number) {
    if(number < 2) {
        return 0;
    }
    for(int i = 2; i < (int)sqrt(number); i++) {
        if(number % i == 0) {
            return 0;
        }
    }
    return 1;
}

// accumulate a list of primes
int main(void) {
    // total # of ints "list" can hold right now
    int capacity = 10;
    // list for holding the primes we find
    int *list = malloc(capacity * sizeof(int));
    int *cur = list; // cursor, initially at beginning
    for(int n = 2; n <= MAX_CANDIDATE; n++) {
        if(is_prime(n)) {
            // am I at the end of the list?
            if(cur == list + capacity) {
                capacity *= 2; // double the # ints "list" can hold
                list = realloc(list, capacity * sizeof(int));
            }
            *cur = n; // put prime on end of list
            cur++; // advance cursor
        }
    }
    printf("Got %ld primes. Last one was %d\n", cur-list, *(cur-1));
    free(list);
    return 0;
}

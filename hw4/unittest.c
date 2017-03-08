/**
Tony Melo - tmelo1@jhu.edu (tmelo1)
EN600.120
Assignment #4
3/7/2017
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "dnasearch.h"

/**
* Test the findOccurances function.
*/
void testMatching(void) {
	char testSequence[10] = "ATCGATCAA";
	int seqLength = 10;
	char pattern[4] = "GAT";
	findOccurances(testSequence, seqLength, pattern);
	printf("\nExpected: %s 3\n", pattern);
}

/**
* Make sure that we can't have a pattern that's longer than the sequence.
*/
void testPatternTooLong(void) {
	int seqLength = 5;
	char pattern[7] = "CATGCG";
	assert(validPattern(pattern, seqLength) == 0);
}


/**
* Make sure valid pattern works.
*/
void testPatternInvalid(void) {
	int seqLength = 5;
	char pattern[4] = "COW";
	assert(validPattern(pattern, seqLength) == 0);
}

/**
* Test that valid pattern doesn't fail for valid ones.
*/
void testValidPatternWorks(void) {
	int seqLength = 5;
	char pattern[4] = "CAT";
	assert(validPattern(pattern, seqLength) == 1);
}

/**
* Make sure that numbers don't slip by either.
*/
void testIsValidForNumbers(void) {
	char test = '9';
	assert(isValid(test) == 0);
}

/**
* Don't wanna turn away a valid character you know?
*/
void testIsValidWorks(void) {
	char test = 'a';
	char test2 = 'C';
	assert(isValid(test) == 1);
	assert(isValid(test2) == 1);
}

/**
* Gotta grow that array.
*/
void testArrayResizing(void) {
	char test[4] = "ABC";
	assert(sizeof(test) == 4);
	growArray(test);
	test[3] = 'D';
	test[4] = 'E';
	test[5] = 'F';
	test[6] = 'G';
	test[7] = '\0';
	assert(strlen(test) == 7); 
}

/**
How to hardcode user input, who knows!
*/
void testReadPattern(void) {
	char test[8];
	int count = readPattern(test);
	printf("\n%d\n", count);
	assert(count == 7);
}

/**
Make sure proper output when nothing is found.
*/
void testNoMatches(void) {
	char dnaSeq[5] = "AAAA";
	char pattern[5] = "GGGG";
	findOccurances(dnaSeq, 5, pattern);
	printf("\nExpected:\nGGGG Not found\n");
}

int main(void) {
	testMatching();
	testPatternTooLong();
	testValidPatternWorks();
	testArrayResizing();
	testPatternInvalid();
	testIsValidForNumbers();
	testReadPattern();
	testNoMatches();
}
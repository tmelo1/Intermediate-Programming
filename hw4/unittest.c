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


void testMatching(void) {
	char testSequence[10] = "ATCGATCAA";
	int seqLength = 10;
	char pattern[4] = "GAT";
	findOccurances(testSequence, seqLength, pattern);
	printf("\nExpected: %s 3\n", pattern);
}

void testPatternTooLong(void) {
	int seqLength = 5;
	char pattern[7] = "CATGCG";
	assert(validPattern(pattern, seqLength) == 0);
}

void testPatternInvalid(void) {
	int seqLength = 5;
	char pattern[4] = "COW";
	assert(validPattern(pattern, seqLength) == 0);
}

void testValidPatternWorks(void) {
	int seqLength = 5;
	char pattern[4] = "CAT";
	assert(validPattern(pattern, seqLength) == 1);
}

void testIsValidForNumbers(void) {
	char test = '9';
	assert(isValid(test) == 0);
}

void testIsValidWorks(void) {
	char test = 'a';
	char test2 = 'C';
	assert(isValid(test) == 1);
	assert(isValid(test2) == 1);
}

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

void testReadPattern(void) {
	char test[8];
	int count = readPattern(test);
	printf("\n%d\n", count);
	assert(count == 7);
}

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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dnasearch.h"

int readPattern(char patternString[]) {
    int counter = 0;
    int length = (int) strlen(patternString);
    while(scanf("%c", &patternString[counter]) != EOF) {
        counter++;
        if (counter == length) {
            growArray(patternString);
        }
    }
    return counter;
}

void growArray(char patternString[]) {
    int length = (int) strlen(patternString);
    char newString[length * 2];
    for (int i = 0; i < length - 1; i++) {
        newString[i] = patternString[i];
    } 
    patternString = newString;
}

int isValid (char c) {
	char check = toupper(c);
	if (check == 'A' || check == 'C' || check == 'G' || check == 'T') {
		return 1;
	}
	return 0;
}

int validPattern(char *pattern, int sequenceLength) {
    if ((int) strlen(pattern) > sequenceLength || (int) strlen(pattern) == 0) {
        return 0;
    }
    for (int i = 0; i < (int) strlen(pattern); i++) {
        if (!isspace(pattern[i]) && !isValid(pattern[i])) {
            return 0;
        }
    }
    return 1;
}

/** Pattern length is n*/
/** Sequence length is m */

void findOccurances(char dnaSeq[], int sequenceLength, char *pattern) {
    int m = strlen(pattern);
    int n = sequenceLength;
    int occurances[sequenceLength];
    int numMatches = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (toupper(pattern[j]) != toupper(dnaSeq[i + j])) {
                break;
            }
        }
        if (j == m) {
            occurances[numMatches++] = i;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%c", toupper(pattern[i]));
    

    if (numMatches == 0) {
        printf(" Not found");
        return;
    }
    for (int i = 0; i < numMatches; i++) {
        printf(" %d", occurances[i]);
    } 
    //printf("\n");
    
}
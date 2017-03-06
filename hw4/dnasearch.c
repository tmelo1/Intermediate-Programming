#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dnasearch.h"

int isValid (char c) {
	char check = toupper(c);
	if (check == 'A' || check == 'C' || check == 'G' || check == 'T') {
		return 1;
	}
	return 0;
}

char* getPattern(char patternList[], int sequenceLength) {
    char *token;
    token = strtok(patternList, " \t\n");
    if (!validPattern(token)) {
        exit(1);
    }
    if ((int) strlen(token) > sequenceLength || (int) strlen(token) == 0) {
        printf("Invalid pattern.");
        exit(3);
    }
    return token;
}

int validPattern(char *pattern) {
    for (int i = 0; i < (int) strlen(pattern); i++) {
        if (!isValid(pattern[i])) {
            printf("Invalid pattern.\n");
            exit(2);
        }
    }
    return 1;
}

/** Pattern length is n*/
/** Sequence length is m */

void findOccurances(char dnaSeq[], int sequenceLength, char *pattern) {
    int patternLength = strlen(pattern);
    int occurances[sequenceLength];
    int match;
    int numMatches = 0;
    for (int i = 0; i <= sequenceLength - patternLength; i++) {
        match = 1;
        for (int j = 0; j <= patternLength; j++) {
            if (toupper(pattern[j]) != toupper(dnaSeq[i + j])) {
                match = 0;
                break;
            }
            if (match) {
                occurances[numMatches++] = i;
            }
        }
    }
    printf("%s: ", pattern);
    for (int i = 0; i < (int) (sizeof(occurances)/sizeof(occurances[0])); i++) {
        printf("%d ", occurances[i]);
    } 
    
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int isValid (char c) {
	char check = toupper(c);
	if (check == 'A' || check == 'C' || check == 'G' || check == 'T') {
		return 1;
	}
	return 0;
}

char* getPattern(char patternList[], int sequenceLength) {
    token = strtok(patternList, " \t\n");
    if (!validPattern(token)) {
        exit(1);
    }
    return token;
}

int validPattern(char *pattern) {
    for (int i = 0; i < sizeof(pattern); i++) {
        if (!isValid(pattern[i])) {
            printf("Invalid pattern.\n");
            exit(2);
        }
    }
    return 1;
}

/** Pattern length is n*/
/** Sequence length is m */

int* findOccurances(char dnaSeq[], int sequenceLength, char *pattern) {
    int patternLength = strlen(pattern);
    int occurances[];
    int match;
    int numMatches = 0;
    for (int i = 0; i <= sequenceLength - patternLength; i++) {
        match = 1;
        for (int j = 0; j <= patternLength; j++) {
            if (pattern[j] != sequenceLength[i + j]) {
                match = 0;
                break;
            }
            if (match) {
                occurances[numMatches++] = i;
            }
        }
    }

}
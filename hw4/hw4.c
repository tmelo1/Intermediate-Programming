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
#include "dnasearch.h"
#define MAX_LENGTH 15000

int main (int argc, const char* argv[]) {
	if (argc != 2) {
		printf("Error, invalid use. Please provide a text file.\n");
		return 1;
	}

	char dnaSequence[MAX_LENGTH + 1];
	int count = 0;
	char in;
    char patternString[MAX_LENGTH + 1];
	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL) {
		printf("Invalid text file\n");
        return 4;
	}
	while (fscanf(infile, "%c", &in) != EOF) {
		if (count > MAX_LENGTH) {
			printf("Invalid text file\n");
			return 2;
		}
		if (isspace(in)) {
			continue;
		}
		if (!isValid(in)) {
			printf("Invalid text file\n");
			return 3;
		}
		dnaSequence[count++] = in;
	}
    if (count == 0) {
        printf("Invalid text file\n");
        return 5;
    }

    int basesRead;
    do {
        basesRead = readPattern(patternString);
    } while (!basesRead);

    char *pattern = strtok(patternString, " \t\n"); 
    while (pattern != NULL) {
        if (!validPattern(pattern, count)) {
            printf("Invalid pattern\n");
            return 6;
        }
        findOccurances(dnaSequence, count, pattern);
        pattern = strtok(NULL, " \t\n");

    }
}

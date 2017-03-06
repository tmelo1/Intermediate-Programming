#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dnasearch.h"

#define MAX_LENGTH 15000

int main (int argc, const char* argv[]) {
	if (argc != 2) {
		printf("Error, invalid use. Please provide a text file.");
		return 1;
	}

	char dnaSequence[MAX_LENGTH + 1];
	int count = 0;
	char in; 
	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL) {
		printf("Invalid text file.");
	}
	while (fscanf(infile, "%c", &in) != EOF) {
		if (count > MAX_LENGTH) {
			printf("Invalid text file.");
			return 2;
		}
		if (isspace(in)) {
			continue;
		}
		if (!isValid(in)) {
			printf("Invalid text file.");
			return 3;
		}
		dnaSequence[count++] = in;
	}

}

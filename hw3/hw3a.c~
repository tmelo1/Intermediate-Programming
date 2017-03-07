/**
Tony Melo
EN600.120
2/28/2017
Assignment #3
tmelo1
tmelo1@jhu.edu
*/

#include "hw3a.h"

int main(int argc, const char* argv[])
{
    
    if(argc != 3) {
       puts("Error, invalid number of parameters.");
       return 2;
    }

    char course[15];
    char binary[33];
    unsigned int decNumber;
    FILE* infile = fopen(argv[1], "r");
    FILE* outfile = fopen(argv[2], "w");
    while(fscanf(infile, "%s", course) != EOF) {
        decNumber = convertToDecimal(course);
        printf("%s  ", course);
        convertToBinary(binary, decNumber);
	for (int i = sizeof(binary) - 2; i >= 0; i--) {
	    printf("%d", binary[i]);
	}
        printf("  %u", decNumber);
        fprintf(outfile, "%u\n", decNumber);
        puts("\n");
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}

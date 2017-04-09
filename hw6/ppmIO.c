#include <stdio.h>
#include <stdlib.h>
#include "ppmIO.h"



Image *readPPM(char *filename) {
	char buffer[16];
	Image *img;
	FILE *file;
	int rgb;
	file = fopen(filename, "rb");
	if (!file) {
		printf("File could not be opened. Exiting.");
		exit(1);
	}

	fgets(buffer, sizeof(buffer), file);
	img = (Image *)malloc(sizeof(Image));
	if (!img) {
		printf("Memory allocation failed. Exiting.");
		exit(1);
	}

	char c = getc(file);
    while (c == '#') {
    	while (getc(file) != '\n') ;
    		c = getc(file);
    }

    ungetc(c, file);

	if (fscanf(file, "%d %d", &img->rows, &img->cols) != 2) {
		printf("Invalid image size. Exiting.");
		exit(1);
	}	

	if (fscanf(file, "%d", &rgb) != 1) {
		printf("Invalid rgb component. Exiting.");
		exit(1);
	}

	if (rgb != 255) {
		printf("Invalid rgb component. Exiting.");
		exit(1);
	}

    while (fgetc(file) != '\n') {
    	img->p = (Pixel*)malloc(img->rows* img->cols * sizeof(Pixel));
    }	

    if (!img) {
    	printf("Memory allocation failed. Exiting.");
    	exit(1);
    }

    img->p = (Pixel *)malloc(img->rows * img->cols * sizeof(Pixel));
    if ((int) fread(img->p, 3 * img->rows, img->cols, file) != img->cols) {
    	printf("Error reading image. Exiting.");
    	exit(1);
    }

    return img;
}

void writePPM(char *filename, Image *img) {
	FILE *file;
	file = fopen(filename, "wb");
	if (!file) {
		printf("Unable to open file. Exiting.");
		exit(1);
	}

	fprintf(file, "P6\n");
	fprintf(file, "%d %d\n", img->rows, img->cols);
	fprintf(file, "%d\n", 255);
	fwrite(img->p, 3 * img->rows, img->cols, file);
	fclose(file);
}
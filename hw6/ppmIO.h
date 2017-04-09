#ifndef PPMIO_H
#define PPMIO_H

typedef struct {
	unsigned char red;
	unsigned char grn;
	unsigned char blue;
} Pixel;

typedef struct {
	int rows;
	int cols;
	Pixel *p;
} Image;

Image *readPPM(char *filename);
void writePPM(char *filename, Image *img);

#endif
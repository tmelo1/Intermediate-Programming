#include "imageManip.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int crop(Image *img, int x1, int y1, int x2, int y2) {
	if ((x2 - x1 < 0) || (y2 - y1) < 0) {
		return 0;
	}
	int count = 0;
	Pixel *temp = malloc(sizeof(Pixel) * (x2 - x1) * (y2 - y1));
	int ind = x1 + y1 * (img->cols);
	for (int i = 0; i < img->rows * img->cols; i++) {
		for (int j = 0; j < (x2 - x1); j++) {
			temp[count] = img->p[ind+j];
			count++;
		}
		ind = ind + (img->cols);
	}
	img->p = temp;
	img->cols = x2 - x1;
	img->rows = y2 - y1;
	return 1;
}

void inversion(Image *img) {
	if (img) {
		for (int i = 0; i < img->rows * img->cols; i++) {
			img->p[i].red = 255 - img->p[i].red;
			img->p[i].grn = 255 - img->p[i].grn;
			img->p[i].blue = 255 - img->p[i].blue;
		}
	}
}

void swap(Image *img) {
	if (img) {
		for (int i = 0; i < img->rows * img->cols; i++) {
			unsigned char tempRed = img->p[i].red;
			unsigned char tempGrn = img->p[i].grn;
			img->p[i].red = tempGrn;
			img->p[i].grn = img->p[i].blue;
			img->p[i].blue = tempRed;
		}
	}
}
void grayscale(Image *img) {
	if (img) {
		for (int i = 0; i < img->rows * img->cols; i++) {
			unsigned char r = img->p[i].red;
			unsigned char g = img->p[i].grn;
			unsigned char b = img->p[i].blue;
			img->p[i].red = 0.30*r + 0.59*g + 0.11*b;
			img->p[i].grn = 0.30*r + 0.59*g + 0.11*b;
			img->p[i].blue = 0.30*r + 0.59*g + 0.11*b;
		}
	}
}

void adjBrightness(Image *img, float delta) {
	if (img) {
		for (int i = 0; i < img->rows * img->cols; i++) {
			unsigned char r = img->p[i].red;
			unsigned char g = img->p[i].grn;
			unsigned char b = img->p[i].blue;
			if (delta * r < 0) {
				img->p[i].red = 0;
			} else if (delta * r > 255) {
				img->p[i].red = 255;
			} else {
				img->p[i].red = delta * r;
			}

			if (delta * g < 0) {
				img->p[i].grn = 0;
			} else if (delta * g > 255) {
				img->p[i].grn = 255;
			} else {
				img->p[i].grn = delta * g;
			}

			if (delta * b < 0) {
				img->p[i].blue = 0;
			} else if (delta * b > 255) {
				img->p[i].blue = 255;
			} else {
				img->p[i].blue = delta * b;
			}

		}
	}
}



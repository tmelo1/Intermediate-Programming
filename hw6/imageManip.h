#ifndef IMAGE_MANIP_H
#define IMAGE_MANIP_H
#include "ppmIO.h"

void crop(Image *img, int x1, int y1, int x2, int y2);
void inversion(Image *img);
void swap(Image *img);
void grayscale(Image *img);
void adjBrightness(Image *img, float delta);

#endif
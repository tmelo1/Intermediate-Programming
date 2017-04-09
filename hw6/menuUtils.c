#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "menuUtils.h"
#include "ppmIO.h"
#include "imageManip.h"
#define TRUE 1
#define FALSE 0

void runMenu(void) {
	int flag = FALSE;
	Image *img;
	char option;
	char buffer[201];
	char writeTo[201];
	menu_prompt();
	int x1;
	int x2;
	int y1;
	int y2;
	float delta;
	
	while (option != 'q') {
		scanf("%c ", &option);
		switch(option) {
			case 'r':
				scanf("%s ", buffer);
				option_r_msg(buffer);
				img = readPPM(buffer);
				flag = TRUE;
				break;
			case 'w':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				scanf("%s ", writeTo);
				option_w_msg(writeTo);
				writePPM(writeTo, img);
				break;
			case 'c':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
				option_c_msg(x1, y1, x2, y2);
				crop(img, x1, y1, x2, y2);
				break;
			case 'i':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				option_i_msg();
				inversion(img);
				break;
			case 's':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				option_s_msg();
				swap(img);
				break;
			case 'g':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				option_g_msg();
				grayscale(img);
				break;
			case 'b':
				if (!flag) {
					no_current_image_prompt();
					break;
				}
				promptDelta();
				scanf("%f ", &delta);
				adjBrightness(img, delta);
				break;

			case 'q':
				exitMsg();
				return;
			default:
				unknown_command_prompt();
				break;

		}
	}
}

void menu_prompt(void) {
	printf("Main menu:\n");
	printf("r <filename> - read image from <filename>\n");
	printf("w <filename> - write image to <filename>\n");
	printf("c <x1> <y1> <x2> <y2> - crop image the the box with the given corners\n");
	printf("i - invert intensities\n");
	printf("s - swap color channels\n");
	printf("g - convert to grayscale\n");
	printf("b <amt> - change brightness (up or down) by the given amount\n");
	printf("q - quit\n");
}

void unknown_command_prompt(void) {
	printf("Error: Unknown command\n");
}

void no_current_image_prompt(void) {
	printf("Error: there is no current image\n");
}

void cropping_failed_prompt(void) {
	printf("Error: cropping failed, image unchanged\n");
}


void option_r_msg(char filename[]) {
	printf("Reading from %s...\n", filename);
}

void option_w_msg(char filename[]) {
	printf("Writing to %s...\n", filename);
}

void option_c_msg(int x1, int y1, int x2, int y2) {
	printf("Cropping region from (%d, %d) to (%d, %d)...\n", x1, y1, x2, y2);
}

void option_i_msg(void) {
	printf("Inverting intensities...\n");
}

void option_s_msg(void) {
	printf("Swapping color channels...\n");
}

void option_g_msg(void) {
	printf("Converting to grayscale...\n");
}

void option_b_msg(float change) {
	printf("Adjusting brightness by %.5f\n", change);
}

void promptDelta(void) {
	printf("Enter a value for delta.\n");
}
void exitMsg(void) {
	printf("Exiting...\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **imgX;
unsigned char *buf;
int size_x;
int size_y;
int crop_left;
int crop_right;
int crop_top;
int crop_bottom;
int i;
int j;
int twidth;
unsigned char ui8;

void init_vars() {
    size_x = 2048;
    size_y = 2048;
    crop_left = 100;
    crop_right = 100;
    crop_top = 100;
    crop_bottom = 100;

    twidth = size_x - crop_left - crop_right;

    buf = (unsigned char *)malloc(twidth * (size_y - crop_top - crop_bottom) * sizeof(unsigned char));
    imgX = (unsigned short **)malloc(size_y * sizeof(unsigned short *));
    for (int idx = 0; idx < size_y; idx++) {
        imgX[idx] = (unsigned short *)malloc(size_x * sizeof(unsigned short));
        for (int jdx = 0; jdx < size_x; jdx++) {
            imgX[idx][jdx] = (unsigned short)((idx * size_x + jdx) % 256);
        }
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

short dither_red[2][16] = {
    { -8,  7, -3,  4, -6,  9, -1,  2, -7,  8, -4,  3, -5,  6, -2,  1 },
    {  8, -7,  3, -4,  6, -9,  1, -2,  7, -8,  4, -3,  5, -6,  2, -1 }
};

short dither_green[2][16] = {
    { -5,  6, -2,  1, -7,  8, -4,  3, -6,  7, -3,  2, -8,  5, -1,  4 },
    {  5, -6,  2, -1,  7, -8,  4, -3,  6, -7,  3, -2,  8, -5,  1, -4 }
};

short dither_blue[2][16] = {
    { -4,  3, -7,  8, -1,  2, -6,  9, -3,  4, -8,  7, -2,  1, -5,  6 },
    {  4, -3,  7, -8,  1, -2,  6, -9,  3, -4,  8, -7,  2, -1,  5, -6 }
};

int i;
int j;
int value;
int x;

unsigned char *red_map[2][16];
unsigned char *green_map[2][16];
unsigned char *blue_map[2][16];

void init_vars() {
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 16; j++) {
            red_map[i][j] = (unsigned char *)malloc(256 * sizeof(unsigned char));
            green_map[i][j] = (unsigned char *)malloc(256 * sizeof(unsigned char));
            blue_map[i][j] = (unsigned char *)malloc(256 * sizeof(unsigned char));
            if (!red_map[i][j] || !green_map[i][j] || !blue_map[i][j]) {
                exit(1);
            }
        }
    }
}
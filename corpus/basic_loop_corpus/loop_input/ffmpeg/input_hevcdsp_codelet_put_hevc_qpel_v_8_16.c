#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint8_t *src;
ptrdiff_t srcstride;
int8_t *filter;

void init_vars() {
    width = 64;
    height = 10000;
    srcstride = 64;

    filter = (int8_t*)malloc(8 * sizeof(int8_t));
    filter[0] = 1; filter[1] = -2; filter[2] = 3; filter[3] = -4;
    filter[4] = 5; filter[5] = -6; filter[6] = 7; filter[7] = -8;

    src = (uint8_t*)malloc((height + 7) * srcstride * sizeof(uint8_t));
    dst = (int16_t*)malloc(height * 64 * sizeof(int16_t));

    for (int i = 0; i < (height + 7) * srcstride; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
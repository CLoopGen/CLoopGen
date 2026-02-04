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
    height = 4000;
    srcstride = 64;

    filter = (int8_t*)malloc(4 * sizeof(int8_t));
    filter[0] = 16;
    filter[1] = 32;
    filter[2] = 48;
    filter[3] = 64;

    src = (uint8_t*)aligned_alloc(64, height * srcstride * sizeof(uint8_t));
    dst = (int16_t*)aligned_alloc(64, height * 64 * sizeof(int16_t));

    for (int i = 0; i < height * srcstride; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
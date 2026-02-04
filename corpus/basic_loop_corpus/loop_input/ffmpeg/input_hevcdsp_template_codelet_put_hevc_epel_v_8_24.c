#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 64;
int x = 0;
int y = 0;
ptrdiff_t srcstride = 64;

uint8_t *src;
int16_t *dst;
int8_t *filter;

void init_vars() {
    src = (uint8_t*)aligned_alloc(64, height * srcstride + 2 * srcstride);
    dst = (int16_t*)aligned_alloc(64, height * 64 * sizeof(int16_t));
    filter = (int8_t*)malloc(4 * sizeof(int8_t));

    for (int i = 0; i < height * srcstride + 2 * srcstride; i++) {
        src[i] = rand() % 256;
    }

    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }

    filter[0] = 16;
    filter[1] = 32;
    filter[2] = -48;
    filter[3] = 64;
}

// Ensure these are defined as external symbols
uint8_t *src;
int16_t *dst;
int8_t *filter;
int height;
int width;
int x;
int y;
ptrdiff_t srcstride;
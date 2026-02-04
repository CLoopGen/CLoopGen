#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x, y;

uint8_t *src;
int16_t *dst;
int8_t *filter;
ptrdiff_t srcstride;

void init_vars() {
    srcstride = width;

    filter = (int8_t*)malloc(4 * sizeof(int8_t));
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;

    src = (uint8_t*)malloc((width + 4) * height * sizeof(uint8_t));
    dst = (int16_t*)malloc(width * sizeof(int16_t) * height);

    for (int i = 0; i < (width + 4) * height; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < width * height; i++) {
        dst[i] = 0;
    }
}
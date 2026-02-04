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
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;

    src = (uint8_t*)malloc((height + 1) * srcstride * sizeof(uint8_t));
    dst = (int16_t*)malloc(height * 64 * sizeof(int16_t));

    for (int i = 0; i < (height + 1) * srcstride; i++) {
        src[i] = rand() & 0xFF;
    }
}
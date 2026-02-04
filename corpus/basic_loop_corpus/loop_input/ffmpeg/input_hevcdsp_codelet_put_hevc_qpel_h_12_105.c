#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

uint16_t *src;
int16_t *dst;
int8_t *filter;
ptrdiff_t srcstride = 1024;

void init_vars() {
    src = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * height * srcstride);
    dst = (int16_t*)aligned_alloc(64, sizeof(int16_t) * height * 64);
    filter = (int8_t*)aligned_alloc(64, sizeof(int8_t) * 8);

    for (int i = 0; i < height * srcstride; i++) {
        src[i] = rand() % 4096;
    }

    for (int i = 0; i < 8; i++) {
        filter[i] = (i == 0 || i == 7) ? -4 : (i == 1 || i == 6) ? -9 : (i == 2 || i == 5) ? 28 : 64;
    }
}
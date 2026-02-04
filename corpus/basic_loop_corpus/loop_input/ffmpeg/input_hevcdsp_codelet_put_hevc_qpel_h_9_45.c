#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x, y;
ptrdiff_t srcstride = 512;

uint16_t *src;
int16_t *dst;
int8_t *filter;

void init_vars() {
    src = aligned_alloc(32, sizeof(uint16_t) * (height + 8) * srcstride);
    dst = aligned_alloc(32, sizeof(int16_t) * height * 64);
    filter = aligned_alloc(32, sizeof(int8_t) * 8);

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i - 3);
    }

    for (int i = 0; i < (height + 8) * srcstride; i++) {
        src[i] = (uint16_t)(i % 257);
    }

    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
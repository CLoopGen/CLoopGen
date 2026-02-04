#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x, y;
ptrdiff_t srcstride = 1024;

uint16_t *src;
int16_t *dst;
int8_t *filter;

void init_vars() {
    src = aligned_alloc(32, sizeof(uint16_t) * (height + 2) * (width + 4));
    dst = aligned_alloc(32, sizeof(int16_t) * height * 64);
    filter = malloc(sizeof(int8_t) * 4);

    for (int i = 0; i < (height + 2) * (width + 4); i++) {
        src[i] = rand() % 1024;
    }

    for (int i = 0; i < 4; i++) {
        filter[i] = (i == 1 || i == 2) ? 32 : -16;
    }

    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
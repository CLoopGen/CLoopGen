#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x, y;

uint16_t *src;
int16_t *dst;
int8_t *filter;
ptrdiff_t srcstride = 512;

void init_vars() {
    src = aligned_alloc(32, sizeof(uint16_t) * (height + 2) * srcstride);
    dst = aligned_alloc(32, sizeof(int16_t) * height * 64);
    filter = malloc(sizeof(int8_t) * 4);

    for (int i = 0; i < (height + 2) * srcstride; i++) {
        src[i] = rand() & 0xFFFF;
    }
    for (int i = 0; i < 4; i++) {
        filter[i] = (rand() % 7) - 3;
    }
}
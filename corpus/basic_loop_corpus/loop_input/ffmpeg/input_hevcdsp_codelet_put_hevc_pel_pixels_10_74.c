#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x;
int y;

uint16_t *src;
int16_t *dst;
ptrdiff_t srcstride = 512;

void init_vars() {
    src = aligned_alloc(32, sizeof(uint16_t) * height * width);
    dst = aligned_alloc(32, sizeof(int16_t) * 64 * height);

    for (int i = 0; i < height * width; i++) {
        src[i] = rand() & 0x3FF;
    }

    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
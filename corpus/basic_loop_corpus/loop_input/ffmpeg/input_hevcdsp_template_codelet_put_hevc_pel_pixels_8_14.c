#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

uint8_t *src;
int16_t *dst;
ptrdiff_t srcstride = 1024;

void init_vars() {
    src = aligned_alloc(32, (size_t)height * srcstride * sizeof(uint8_t));
    dst = aligned_alloc(32, (size_t)height * 64 * sizeof(int16_t));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * srcstride + j] = rand() % 256;
        }
    }

    for (int i = 0; i < height * 64; i++) {
        dst[i] = 0;
    }
}
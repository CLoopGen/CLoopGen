#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int size;
int bpp;
int i;

void init_vars() {
    bpp = 4;
    size = 64 * 1024 * 1024 / sizeof(uint8_t);
    i = bpp;

    dst = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));
    src = (uint8_t*)aligned_alloc(32, size * sizeof(uint8_t));

    for (int j = 0; j < size; j++) {
        dst[j] = rand() % 256;
        src[j] = rand() % 256;
    }
}
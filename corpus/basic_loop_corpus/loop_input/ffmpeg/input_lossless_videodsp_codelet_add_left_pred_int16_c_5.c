#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
unsigned int mask;
ptrdiff_t w;
unsigned int acc;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01s on modern CPU)
    w = data_size / sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(32, data_size);
    dst = (uint16_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        exit(1);
    }

    for (ptrdiff_t j = 0; j < w; j++) {
        src[j] = (uint16_t)(j & 0xFFFF);
    }

    mask = 0x7FFF;
    acc = 0;
    i = 0;
}
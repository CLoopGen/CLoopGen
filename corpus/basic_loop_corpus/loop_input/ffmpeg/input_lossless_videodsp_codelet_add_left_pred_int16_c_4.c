#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
unsigned int mask = 0xFFFF;
ptrdiff_t w;
unsigned int acc = 0;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128MB of total data (64M elements * 2 bytes)
    w = data_size / sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(32, data_size);
    dst = (uint16_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < w; idx++) {
        src[idx] = (uint16_t)(idx & 0xFF);
        dst[idx] = 0;
    }

    acc = 0;
    mask = 0x7FFF;
}
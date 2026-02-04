#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t w;
long i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPUs

    dst = aligned_alloc(32, data_size);
    src = aligned_alloc(32, data_size);

    if (!dst || !src) {
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        dst[j] = rand() % 256;
        src[j] = rand() % 256;
    }

    w = data_size - 0;
    i = 0;
}
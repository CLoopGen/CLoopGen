#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int src_size;
int i;

void init_vars() {
    src_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    src = (uint8_t *)aligned_alloc(32, src_size);
    dst = (uint8_t *)aligned_alloc(32, src_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < src_size; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }
}
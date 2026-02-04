#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int i;
int num_pixels;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    num_pixels = data_size / sizeof(uint16_t);

    src = (uint8_t *)aligned_alloc(16, data_size);
    dst = (uint8_t *)aligned_alloc(16, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < data_size; j++) {
        src[j] = rand() % 256;
    }

    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int i;
int num_pixels;

void init_vars() {
    num_pixels = 64 * 1024 * 1024; // 64 million pixels -> ~256MB total data, ensures loop runs long enough

    src = (uint8_t*)aligned_alloc(32, 4 * num_pixels);
    dst = (uint8_t*)aligned_alloc(32, 3 * num_pixels);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 4 * num_pixels; j++) {
        src[j] = rand() % 256;
    }

    for (int j = 0; j < 3 * num_pixels; j++) {
        dst[j] = 0;
    }

    i = 0;
}
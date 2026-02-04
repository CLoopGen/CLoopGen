#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
uint16_t *src;
uint16_t *dst;
int j;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128MB of total data (64M elements of uint16_t)
    w = data_size / sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(32, data_size + w * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, w * sizeof(uint16_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source array with offset so that src[-j] is valid for j in [0, w)
    src += w; // Make room for negative indexing: indices [-w, -1] will access base[0, w-1]

    for (int i = 0; i < w; i++) {
        src[-i] = (uint16_t)(i & 0xFFFF); // Ensure defined behavior for negative index
        dst[i] = 0; // Clear destination
    }
}
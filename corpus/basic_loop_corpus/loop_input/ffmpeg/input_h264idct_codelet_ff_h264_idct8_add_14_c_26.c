#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int i;
int32_t *block;

void init_vars() {
    const size_t data_size = 1 << 24; // ~16.7 million int32_t elements, ~64 MB
    block = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    if (!block) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        block[idx] = (int32_t)(idx % 256 - 128);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *out;
int blockstodecode;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of int32_t data
    blockstodecode = data_size / sizeof(int32_t);

    out = (int32_t*)aligned_alloc(32, data_size);
    if (!out) {
        exit(1);
    }

    for (int j = 0; j < blockstodecode; j++) {
        out[j] = rand();
    }
}
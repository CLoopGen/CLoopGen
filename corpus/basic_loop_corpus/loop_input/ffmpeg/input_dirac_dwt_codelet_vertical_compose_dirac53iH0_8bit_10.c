#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int16_t *b0;
int16_t *b1;
int16_t *b2;

void init_vars() {
    // Target approximately 0.01 seconds of computation
    // Assume modern CPU can do ~1e9 operations/sec -> aim for ~1e7 operations
    // The loop has about 5-10 operations per iteration, so 2^20 (~1M) elements should be sufficient
    const size_t num_elements = 1 << 20;  // 1,048,576 elements

    width = (int)num_elements;

    b0 = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        b0[idx] = (int16_t)(idx % 32768);
        b1[idx] = (int16_t)((idx + 100) % 32768);
        b2[idx] = (int16_t)((idx + 200) % 32768);
    }
}
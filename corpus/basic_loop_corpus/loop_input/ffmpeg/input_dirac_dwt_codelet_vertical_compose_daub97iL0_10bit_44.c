#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Estimate: ~100 million operations typical on modern CPU
    // Use about 64M elements for reasonable timing given simple arithmetic
    width = 64 * 1024 * 1024 / sizeof(int32_t); // ~64M bytes per array

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with non-zero values to ensure meaningful computation
    for (int j = 0; j < width; j++) {
        b0[j] = (int32_t)(j % 1000);
        b1[j] = (int32_t)((j + 100) % 1500);
        b2[j] = (int32_t)((j + 200) % 2000);
    }
}
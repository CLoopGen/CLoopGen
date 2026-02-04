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
    // Use 8 million elements as a reasonable middle ground for arithmetic intensity
    size_t num_elements = 8000000; // ~32 MB per array (total ~96 MB)
    width = (int)num_elements;

    // Allocate arrays
    b0 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, num_elements * sizeof(int32_t));

    // Initialize with non-zero values to ensure meaningful computation
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < num_elements; ++idx) {
        b0[idx] = (int32_t)(rand() % 256);
        b1[idx] = (int32_t)(rand() % 256);
        b2[idx] = (int32_t)(rand() % 256);
    }
}
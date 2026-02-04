#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint16_t *src;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    src = (uint16_t*)aligned_alloc(32, data_size);
    
    if (!src) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize source data with predictable pattern
    const size_t num_elements = data_size / sizeof(uint16_t);
    for (size_t idx = 0; idx < num_elements; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    // Set stride to a reasonable value to ensure valid access
    // We need: i - stride >= 0 and 4 + i - stride < num_elements when i in [0,3]
    // So: stride <= 0 and 4 + 3 - stride < num_elements -> stride > 7 - num_elements
    // Choose negative stride within bounds
    stride = -4; // This makes accesses at indices 4,5,6,7 and 8,9,10,11

    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
}
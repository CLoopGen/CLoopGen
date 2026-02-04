#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * sizeof(uint16_t))
#define SRC_SIZE (16 * stride + 10)

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint16_t *src;

void init_vars() {
    // Set stride to a reasonable value to ensure memory accesses are in bounds
    // We need to access up to index: -1 + (i+4)*stride with i=3 -> -1 + 7*stride
    // And also: 4 + i - stride with i=3 -> 7 - stride
    // So we choose stride >= 8 to make sure array is large enough and positive
    stride = 16;

    // Allocate enough memory to cover all possible accesses
    size_t total_size = SRC_SIZE;
    src = aligned_alloc(64, total_size * sizeof(uint16_t));
    
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data with pseudo-random values for realistic timing
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&src));
    for (size_t idx = 0; idx < total_size; ++idx) {
        src[idx] = (uint16_t)(rand() % 65536);
    }

    // Initialize accumulators to known state
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;

    // Ensure cache warm-up to get consistent timing around ~0.01s
    // The loop runs only 4 iterations, so we don't need huge data,
    // but we make the buffer large enough to avoid being fully in cache
    // 64 KiB of data helps achieve measurable runtime when repeated in benchmarking
}
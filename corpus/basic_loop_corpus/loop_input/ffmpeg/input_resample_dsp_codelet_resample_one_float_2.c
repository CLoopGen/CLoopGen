#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_size;
int64_t index2;
int64_t incr;
float *dst;
float *src;
int dst_index;

void init_vars() {
    // Set problem size to approximately 64 million elements for ~0.01 sec runtime
    dst_size = 64 * (1 << 10); // 64K elements, about 256KB of data

    // Allocate memory for arrays
    dst = (float*)aligned_alloc(32, dst_size * sizeof(float));
    src = (float*)aligned_alloc(32, dst_size * sizeof(float));

    // Initialize src array with some values
    for (int i = 0; i < dst_size; i++) {
        src[i] = (float)(i * 2);
    }

    // Set fixed-point index: upper 32 bits used as integer part
    index2 = ((int64_t)1 << 32); // Start at index 1.0 (fixed point)
    incr = (int64_t)(1.0 * (1LL << 32)); // Increment by 1.0 per iteration

    // Ensure that index2 >> 32 stays within bounds during loop
    // With incr = 1 and starting at 1, final index = 1 + dst_size - 1 = dst_size
    // So we need src size >= dst_size + 1; but we set both to same size above.
    // Adjust src size to be larger to prevent out-of-bounds
    free(src);
    src = (float*)aligned_alloc(32, (dst_size + 1) * sizeof(float));
    for (int i = 0; i <= dst_size; i++) {
        src[i] = (float)(i * 2);
    }
}
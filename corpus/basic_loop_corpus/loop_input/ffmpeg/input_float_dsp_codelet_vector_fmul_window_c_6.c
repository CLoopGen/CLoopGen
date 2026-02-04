#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src0;
float *src1;
float *win;
int len;
int i;
int j;

void init_vars() {
    // Set length to achieve approximately 0.01 seconds runtime
    // The loop runs for 'len' iterations (from -len to -1)
    // Use ~64M elements to stay within typical L3 cache but provide enough work
    len = 1 << 23; // 8,388,608 elements per array

    // Allocate arrays with sufficient size to cover negative and positive indices
    // Access in loop: src0[i], src1[j], win[i], win[j] where i from -len to -1, j from len-1 down to 0
    // So we need:
    //   src0[-len] to src0[-1]  --> base index -len, so allocate at least len elements starting from -len
    //   src1[0] to src1[len-1]  --> normal 0-based indexing
    //   win[-len] to win[len-1] --> both negative and positive indices

    // We use offset pointers: allocate extra space and shift pointer so that index -len is valid
    ptrdiff_t offset = len;
    size_t total_size = 2 * len; // from -len to len-1

    float *base_dst = (float*)aligned_alloc(32, total_size * sizeof(float));
    float *base_src0 = (float*)aligned_alloc(32, total_size * sizeof(float));
    float *base_src1 = (float*)aligned_alloc(32, total_size * sizeof(float));
    float *base_win = (float*)aligned_alloc(32, total_size * sizeof(float));

    // Initialize all memory to avoid undefined behavior
    for (size_t k = 0; k < total_size; k++) {
        base_dst[k] = 0.0f;
        base_src0[k] = (float)(k - offset) * 0.001f;
        base_src1[k] = (float)(k - offset) * 0.002f;
        base_win[k] = 0.5f + (float)(k % 100) * 0.01f;
    }

    // Set global pointers such that:
    //   src0[i] with i in [-len, -1] is valid -> src0 should point to base_src0 + offset
    //   dst[i] same
    //   win[i] and win[j] access both negative and positive, so win points to base_win + offset
    //   src1[j] with j in [0, len-1] -> can use base_src1 directly or shifted consistently

    dst = base_dst + offset;
    src0 = base_src0 + offset;
    src1 = base_src1 + offset;
    win = base_win + offset;

    // Ensure no out-of-bounds: the loop accesses:
    //   i from -len to -1 => valid indices in [-len, -1]
    //   j from len-1 down to 0 => valid indices in [0, len-1]
    // All arrays are accessible in index range [-len, len-1] due to offset allocation
}

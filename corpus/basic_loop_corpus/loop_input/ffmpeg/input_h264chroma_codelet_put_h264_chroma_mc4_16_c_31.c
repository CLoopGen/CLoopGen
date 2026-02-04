#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
ptrdiff_t step;

static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 31;
    h = 4096;  // Number of iterations
    stride = 4;  // Stride in elements (must be at least 4 for safe access)
    step = 4;   // Step offset within src array

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // Each iteration accesses up to src[step + 3], so we need at least (h * stride) + step + 3 elements
    ptrdiff_t total_src_size = (h * stride) + step + 4;
    ptrdiff_t total_dst_size = h * stride;

    dst_buffer = aligned_alloc(32, total_dst_size * sizeof(uint16_t));
    src_buffer = aligned_alloc(32, total_src_size * sizeof(uint16_t));

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src data to non-zero values for meaningful computation
    for (ptrdiff_t idx = 0; idx < total_src_size; ++idx) {
        src_buffer[idx] = (uint16_t)(idx % 31337);
    }

    // Set pointers
    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
    free(src_buffer);
}
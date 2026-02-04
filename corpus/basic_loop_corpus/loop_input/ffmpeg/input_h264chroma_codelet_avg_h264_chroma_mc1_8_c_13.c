#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
int step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 5;
    E = 3;
    step = 1;
    h = 2 * 1024 * 1024; // ~2M iterations to target ~0.01 sec runtime on modern CPU
    stride = 1;

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // We access src[0] and src[step], so need at least (h * stride + step) elements
    size_t src_size = (size_t)(h * stride + step);
    size_t dst_size = (size_t)(h * stride);

    src_buffer = (uint8_t*)aligned_alloc(32, src_size * sizeof(uint8_t));
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to non-zero for realistic computation
    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = (uint8_t)((idx * 71) % 256);
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = (uint8_t)((idx * 13) % 256);
    }

    // Set pointers
    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((destructor)) void cleanup() {
    free(dst_buffer);
    free(src_buffer);
}
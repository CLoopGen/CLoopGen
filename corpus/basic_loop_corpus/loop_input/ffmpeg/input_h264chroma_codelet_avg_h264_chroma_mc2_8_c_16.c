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
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Set constants
    A = 17;  // arbitrary coefficient
    E = 33;  // arbitrary coefficient
    step = 1;
    h = 4096;  // number of rows
    stride = 4096;  // bytes per row

    // Allocate buffers with sufficient size to avoid out-of-bounds access
    // We access up to src[step + 1] => need at least stride + 2 bytes per row, but we have h rows
    size_t total_size = (size_t)stride * (size_t)h + 16;  // extra padding for safety

    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or some deterministic pattern)
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
        dst_buffer[idx] = (uint8_t)((idx * 3) & 0xFF);
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
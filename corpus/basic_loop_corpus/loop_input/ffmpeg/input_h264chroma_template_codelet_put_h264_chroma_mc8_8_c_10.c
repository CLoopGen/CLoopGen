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
    // Set parameters
    stride = 16;
    h = 1000000;  // Adjust to get ~0.01 sec runtime on modern CPU
    A = 45;
    E = 23;
    step = stride;

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // Each iteration accesses up to src[step + 7], so we need at least (h * stride) + 7 + 1 elements
    size_t buffer_size = (h * stride) + 8;

    dst_buffer = aligned_alloc(32, buffer_size);
    src_buffer = aligned_alloc(32, buffer_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;

    // Initialize src data to avoid undefined behavior
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }
}
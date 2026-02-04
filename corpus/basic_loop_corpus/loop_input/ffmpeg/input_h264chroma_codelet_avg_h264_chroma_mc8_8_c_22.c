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
    // Initialize scalar variables
    A = 17;
    E = 23;
    h = 10000;  // Adjusted to achieve ~0.01s runtime
    stride = 16;
    step = 8;

    // Allocate buffers with sufficient size to prevent out-of-bounds access
    // Each iteration accesses up to index 7, and src[step + 7] => src[8+7]=src[15]
    // So we need at least (h * stride) + 16 bytes per buffer
    size_t dst_size = (h * stride) + 16;
    size_t src_size = (h * stride) + 16;

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or predictable values)
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = idx & 0xFF;
    }
    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = (idx * 7) & 0xFF;
    }

    // Set pointers
    dst = dst_buffer;
    src = src_buffer;
}
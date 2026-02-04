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
static ptrdiff_t buffer_size;

void init_vars() {
    // Set up constants
    A = 15;
    E = 17;
    step = 16;
    stride = 16;
    h = 100000;  // Adjusted to achieve ~0.01s runtime

    // Calculate approximate data size: each iteration accesses up to src[step+7]
    // So we need at least (h * stride) + step + 8 bytes of source data
    buffer_size = (h * stride) + step + 8;

    // Allocate buffers with sufficient padding
    dst_buffer = aligned_alloc(32, buffer_size);
    src_buffer = aligned_alloc(32, buffer_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    // Initialize src with non-zero data to make computation meaningful
    for (ptrdiff_t j = 0; j < buffer_size; j++) {
        src_buffer[j] = (uint8_t)(j & 0xFF);
    }

    // Initialize dst to zero
    for (ptrdiff_t j = 0; j < buffer_size; j++) {
        dst_buffer[j] = 0;
    }

    // Set pointers
    dst = dst_buffer;
    src = src_buffer;
}

// Cleanup function to avoid memory leaks (not required by spec but good practice)
void cleanup_vars() {
    if (dst_buffer) free(dst_buffer);
    if (src_buffer) free(src_buffer);
}
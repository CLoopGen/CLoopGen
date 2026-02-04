#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
ptrdiff_t step;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 23;
    h = 10000; // Number of loop iterations
    step = 4;

    // Stride in bytes: ensure alignment and spacing to prevent overlap
    stride = 64;

    // Allocate large buffers to achieve desired runtime
    dst_buffer = aligned_alloc(64, DATA_SIZE);
    src_buffer = aligned_alloc(64, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = (uint8_t)((i >> 8) & 0xFF);
    }

    // Set pointers to middle of buffers to allow safe access with step and stride
    size_t offset = (DATA_SIZE / 2) & ~(63); // Align to cache line
    dst = dst_buffer + offset;
    src = src_buffer + offset;

    // Ensure that the loop will not go out of bounds
    // Each iteration accesses up to [step + 3], so we need at least (h * stride) + step + 3 bytes available
    ptrdiff_t required_space = h * stride + step + 4;
    if ((dst - dst_buffer) + required_space >= DATA_SIZE ||
        (src - src_buffer) + required_space >= DATA_SIZE) {
        fprintf(stderr, "Buffer overflow risk avoided by reducing h\n");
        h = (DATA_SIZE - offset - step - 4) / stride;
    }
}
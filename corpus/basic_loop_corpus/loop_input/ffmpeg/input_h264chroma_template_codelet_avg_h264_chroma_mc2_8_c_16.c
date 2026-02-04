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

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB total data size

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 3;
    step = 1;
    h = DATA_SIZE / 2;  // Adjust so we don't exceed buffer bounds in loop
    stride = 2;

    // Allocate large buffers to ensure meaningful runtime (~0.01 sec)
    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers with predictable data
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 251);
        dst_buffer[idx] = (uint8_t)((idx + 13) % 251);
    }

    // Set pointers to middle of buffers to allow safe access with offsets
    dst = dst_buffer + 1;
    src = src_buffer + 1;

    // Ensure that during loop: dst[1] and src[step+1] are valid
    // With h = DATA_SIZE/2 and proper alignment, and our stride=2,
    // we require at most h*stride + 1 byte forward access -> make sure within bounds
}
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

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01s estimate)
static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 17;  // arbitrary non-zero coefficient
    E = 23;  // arbitrary non-zero coefficient
    h = DATA_SIZE / 8; // each iteration processes 8 bytes, so set h accordingly
    step = 1; // step offset within the array
    stride = 8; // advance by 8 bytes per row

    // Seed and initialize random data for predictable but varied input
    srand((unsigned int)time(NULL));
    
    // Allocate buffers with padding to prevent out-of-bounds access
    dst_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE + 32);
    src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE + 32 + stride * h);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source and destination memory
    for (size_t i = 0; i < DATA_SIZE + 32; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < DATA_SIZE; i++) {
        dst_buffer[i] = rand() & 0xFF;
    }

    // Set pointers to valid starting positions
    dst = dst_buffer;
    src = src_buffer;

    // Ensure that throughout the loop:
    //   src[step + 7] remains in bounds when src += stride each iteration
    // So total required src size: h * stride + step + 8
    ptrdiff_t required_src_size = h * stride + step + 8;
    if (required_src_size > DATA_SIZE + 32) {
        // Reallocate if necessary (should not happen with current settings)
        free(src_buffer);
        src_buffer = (uint8_t*)aligned_alloc(32, required_src_size);
        if (!src_buffer) {
            fprintf(stderr, "Reallocation failed\n");
            exit(1);
        }
        for (ptrdiff_t i = 0; i < required_src_size; i++) {
            src_buffer[i] = rand() & 0xFF;
        }
        src = src_buffer;
    }
}
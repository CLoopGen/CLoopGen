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

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB for sufficient runtime (~0.01 sec)

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Initialize scalar variables
    A = 42;  // arbitrary non-zero coefficient
    h = DATA_SIZE / 2;  // each iteration writes 2 bytes, so we adjust loop count accordingly
    stride = 2;  // advance by 2 bytes per row (minimal stride for 2-element access)

    // Allocate buffers with padding to avoid out-of-bounds access
    dst_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        exit(EXIT_FAILURE);
    }

    // Initialize source data
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Set pointers
    dst = dst_buffer;
    src = src_buffer;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_wrap;
uint8_t *src;
int src_wrap;
int width;
int height;
int w;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Set dimensions to achieve roughly 0.01s runtime on modern CPU
    // Empirical tuning: use image-like data with moderate size
    width = 512;
    height = 256;
    src_wrap = 512;  // stride for 8x8 block access
    dst_wrap = 512;

    // Total data sizes based on access patterns
    size_t src_size = (height * 8 + 8) * src_wrap;  // account for all src accesses
    size_t dst_size = height * dst_wrap + width;     // enough for dst writes

    // Allocate buffers
    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data to avoid undefined behavior
    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Initialize destination to zero
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }

    // Set pointers to valid starting positions within buffers
    src = src_buffer + 8;  // leave room for negative indexing if needed
    dst = dst_buffer;

    // Ensure initial conditions prevent out-of-bounds access
    // Inner loop reads 8 consecutive elements per iteration, 8 times with src_wrap step
    // So we require at least 8 rows of 8 elements in a column-wise fashion
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Allocate input and output buffers
    src_buffer = (uint8_t*)aligned_alloc(32, TOTAL_ELEMENTS);
    dst_buffer = (uint8_t*)aligned_alloc(32, TOTAL_ELEMENTS);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set up parameters
    width = 1024;  // Must be multiple of 2 due to i += 2
    src_stride = width * 2;  // Stride larger than width to simulate 2D layout
    dst_stride = width * 3;  // RGB-like format with 3 bytes per pixel

    // Ensure that the loop accesses stay within bounds
    // Maximum src index: (1)*src_stride + 2*(1) = src_stride + 2
    // Total src needed: (width/2) * 2*2 = 2*width (due to src += 4 each iteration)
    // Total dst needed: (width/2) * 6 = 3*width

    size_t min_src_size = (width / 2) * 4;
    size_t min_dst_size = (width / 2) * 6;

    if (min_src_size > TOTAL_ELEMENTS || min_dst_size > TOTAL_ELEMENTS) {
        fprintf(stderr, "Buffer sizes too small\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;
}
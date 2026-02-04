#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime
#define SRC_HEIGHT 12
#define DST_HEIGHT 8

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static uint8_t cm_buffer[512];

void init_vars() {
    // Allocate buffers
    src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    dst_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize lookup table cm with identity mapping + offset
    for (int idx = 0; idx < 512; idx++) {
        cm_buffer[idx] = (uint8_t)((idx > 255) ? 255 : (idx < 0) ? 0 : idx);
    }

    // Initialize source data with non-zero values
    for (size_t j = 0; j < DATA_SIZE; j++) {
        src_buffer[j] = (uint8_t)(j % 256);
    }

    // Initialize destination buffer
    memset(dst_buffer, 0, DATA_SIZE);

    // Set parameters
    srcStride = 1;
    dstStride = 1;
    w = DATA_SIZE / SRC_HEIGHT; // Adjust so we don't overflow

    // Ensure w is within safe bounds based on buffer size
    if (w > DATA_SIZE / SRC_HEIGHT) {
        w = DATA_SIZE / SRC_HEIGHT;
    }

    // Point src near middle of buffer to allow negative indexing
    ptrdiff_t offset = 2 * srcStride;
    src = src_buffer + offset;

    // Ensure there's enough room after src for all required rows
    size_t required_span = (SRC_HEIGHT - 1) * srcStride + w;
    if (required_span > DATA_SIZE - offset) {
        w = (DATA_SIZE - offset - (SRC_HEIGHT - 1) * srcStride);
    }

    // Point dst appropriately
    dst = dst_buffer;

    // Point cm to our buffer
    cm = cm_buffer + 256; // Centered around typical signed results

    // Initialize loop index
    i = 0;
}
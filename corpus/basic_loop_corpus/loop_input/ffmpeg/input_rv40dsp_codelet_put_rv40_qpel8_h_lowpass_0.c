#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec on modern CPU)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int C1;
int C2;
int SHIFT;
uint8_t *cm;
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;
static uint8_t *internal_cm_buffer;

void init_vars() {
    // Initialize constants
    C1 = 3;
    C2 = 4;
    SHIFT = 5;
    h = 1000; // Number of rows to process

    srcStride = 20; // Must be >= 12 to allow src[-2] to src[10]
    dstStride = 16; // 8 bytes written per row

    // Allocate buffers with padding to prevent out-of-bounds access
    internal_src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    internal_dst_buffer = (uint8_t*)aligned_alloc(32, h * dstStride + 32);
    internal_cm_buffer = (uint8_t*)aligned_alloc(32, 256);

    // Ensure src has enough padding: we access from -2 to 10 => need at least 13 elements per row, but use stride
    // Total required src size: h rows, each requiring up to src[i*srcStride + 10], and starting from -2
    if (srcStride < 13) srcStride = 13;
    size_t total_src_size = h * srcStride + 12; // +12 for initial offset and margin

    if (total_src_size > DATA_SIZE) {
        total_src_size = DATA_SIZE;
    }

    // Initialize source data with pseudo-random content
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < total_src_size; idx++) {
        internal_src_buffer[idx] = (uint8_t)(rand() % 256);
    }

    // Initialize cm lookup table (maps signed 8-bit shifted values to clamped byte)
    for (int idx = 0; idx < 256; idx++) {
        // Simulate typical clipping: assume input range maps to 0-255
        internal_cm_buffer[idx] = (uint8_t)idx;
    }
    // Handle possible negative indices or overflow via modulo behavior if needed
    // In practice, cm is often a clipping function: clip(x) = min(255, max(0, x))

    // Set pointers with offset: src starts at index 2 to allow src[-2] safely
    src = internal_src_buffer + 2;
    dst = internal_dst_buffer;
    cm = internal_cm_buffer;
}

// Cleanup function to avoid memory leaks (not called here, but available)
void free_vars() {
    if (internal_dst_buffer) free(internal_dst_buffer);
    if (internal_src_buffer) free(internal_src_buffer);
    if (internal_cm_buffer) free(internal_cm_buffer);
}
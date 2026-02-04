#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB for sufficient runtime (~0.01 sec on modern CPU)

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;
static uint8_t *internal_cm_buffer;

void init_vars() {
    const int alignment = 32;
    const int padded_width = 16; // Ensure we can access src[-2] to src[10] safely
    const int total_width = padded_width + 12; // Add padding for left/right
    const int height = DATA_SIZE / (total_width * sizeof(uint8_t));
    
    h = height > 0 ? height : 1;

    // Allocate aligned buffers
    if (posix_memalign((void**)&internal_src_buffer, alignment, h * (total_width) * sizeof(uint8_t)) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&internal_dst_buffer, alignment, h * padded_width * sizeof(uint8_t)) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&internal_cm_buffer, alignment, 256 * sizeof(uint8_t)) != 0) {
        exit(1);
    }

    // Initialize cm lookup table: clamp to [0,255]
    for (int idx = 0; idx < 256; idx++) {
        internal_cm_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set pointers
    src = internal_src_buffer + 2; // Allow src[-2]
    dst = internal_dst_buffer;
    cm = internal_cm_buffer;

    // Stride setup
    srcStride = total_width;
    dstStride = padded_width;

    // Initialize src data with pseudo-random values
    srand((unsigned int)time(NULL));
    for (int y = 0; y < h; y++) {
        uint8_t *row = internal_src_buffer + y * srcStride;
        for (int x = 0; x < total_width; x++) {
            row[x] = (uint8_t)(rand() & 0xFF);
        }
    }

    // Zero-initialize destination
    memset(internal_dst_buffer, 0, h * padded_width * sizeof(uint8_t));
}
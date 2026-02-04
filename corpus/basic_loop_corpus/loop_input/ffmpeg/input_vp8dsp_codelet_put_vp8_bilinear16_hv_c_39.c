#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
int h;
int c;
int d;
int x;
int y;
uint8_t *tmp;

#define DATA_SIZE (64 * 1024 * 1024) // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)

static uint8_t *dst_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    h = 4096; // Adjust to ensure proper data distribution
    c = 5;
    d = 3;
    dstride = 64; // Must be >= 16 for valid access

    // Allocate buffers
    dst_buffer = aligned_alloc(32, h * dstride * sizeof(uint8_t));
    tmp_buffer = aligned_alloc(32, DATA_SIZE * sizeof(uint8_t));

    // Initialize pointers
    dst = dst_buffer;
    tmp = tmp_buffer;

    // Ensure tmp has enough data: each iteration accesses x and x+16, so we need at least (h * 16 + 16)
    if (DATA_SIZE < (size_t)(h * 16 + 16)) {
        // Re-allocate or adjust h to fit
        free(tmp_buffer);
        tmp_buffer = aligned_alloc(32, (h * 16 + 16) * sizeof(uint8_t));
        tmp = tmp_buffer;
    }

    // Initialize tmp with non-zero values for meaningful computation
    for (int i = 0; i < h * 16 + 16; ++i) {
        tmp[i] = rand() & 0xFF;
    }

    // Zero-initialize output
    for (int i = 0; i < h * dstride; ++i) {
        dst_buffer[i] = 0;
    }
}
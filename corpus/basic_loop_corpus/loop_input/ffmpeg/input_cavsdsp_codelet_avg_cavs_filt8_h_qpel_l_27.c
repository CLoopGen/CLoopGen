#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB total data size
#define WIDTH 8
#define PADDING 12

static uint8_t *internal_dst_data;
static uint8_t *internal_src_data;
static uint8_t internal_cm_data[256];

void init_vars() {
    const int aligned_width = WIDTH + 2 * PADDING; // Add padding for safe negative indexing
    const int total_rows = DATA_SIZE / aligned_width;
    h = total_rows;

    // Allocate memory with padding
    internal_dst_data = (uint8_t*)aligned_alloc(32, (size_t)h * aligned_width * sizeof(uint8_t));
    internal_src_data = (uint8_t*)aligned_alloc(32, (size_t)h * (aligned_width + 12) * sizeof(uint8_t)); // Extra for right-side access

    if (!internal_dst_data || !internal_src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize cm lookup table: identity map with clipping
    for (int idx = 0; idx < 256; ++idx) {
        internal_cm_data[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set up pointers
    dst = internal_dst_data + PADDING; // Allow access from dst[-PADDING] to dst[WIDTH+PADDING-1]
    src = internal_src_data + PADDING + 2; // Account for src[-2] access and extra padding on right
    dstStride = aligned_width;
    srcStride = aligned_width + 12;

    // Initialize src and dst data with non-zero values
    for (int row = 0; row < h; ++row) {
        uint8_t* s_row = internal_src_data + row * (aligned_width + 12);
        uint8_t* d_row = internal_dst_data + row * aligned_width;
        for (int j = 0; j < aligned_width + 12; ++j) {
            s_row[j] = (uint8_t)((j * 7 + row * 13) % 251);
        }
        for (int j = 0; j < aligned_width; ++j) {
            d_row[j] = (uint8_t)((j * 3 + row * 17) % 251);
        }
    }

    cm = internal_cm_data;
}
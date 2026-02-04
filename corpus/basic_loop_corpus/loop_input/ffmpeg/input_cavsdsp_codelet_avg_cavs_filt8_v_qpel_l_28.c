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

#define DATA_SIZE (128 << 20) // 128 MB of total input data

static uint8_t *internal_dst_base;
static uint8_t *internal_src_base;
static uint8_t *internal_cm;

void init_vars() {
    const int filter_offset = 10;
    const int output_height = 8;
    const int width = 16384; // Adjust to control loop iterations for ~0.01s runtime

    // Set strides and dimensions
    srcStride = width;
    dstStride = width;
    w = width;
    i = 0;

    // Allocate extra boundary space for safe [-2*srcStride] access
    size_t src_pitch = srcStride * (filter_offset + output_height);
    internal_src_base = aligned_alloc(32, src_pitch * sizeof(uint8_t));
    if (!internal_src_base) abort();
    src = internal_src_base + 2 * srcStride; // Adjust so that -2*srcStride is valid

    // DST needs at least 8 rows accessible from base pointer
    size_t dst_pitch = dstStride * output_height;
    internal_dst_base = aligned_alloc(32, dst_pitch * sizeof(uint8_t));
    if (!internal_dst_base) abort();
    dst = internal_dst_base;

    // cm table: 256-byte lookup table indexed by signed 8-bit offset values
    internal_cm = aligned_alloc(32, 256 * sizeof(uint8_t));
    if (!internal_cm) abort();
    cm = internal_cm;

    // Initialize cm with identity-like mapping: cm[x] = abs(x) clipped to 255
    for (int j = 0; j < 256; j++) {
        cm[j] = (uint8_t)(j);
    }

    // Initialize src with dummy pixel data
    for (int j = 0; j < src_pitch; j++) {
        internal_src_base[j] = (uint8_t)(j % 256);
    }

    // Initialize dst with zeros
    memset(internal_dst_base, 0, dst_pitch);
}
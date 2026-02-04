#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
uint8_t *cm;
int i;

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_cm[256];

void init_vars() {
    // Initialize constants
    dstStride = 32;
    srcStride = 32;
    h = (TOTAL_ELEMENTS / dstStride) - 1;  // Ensure we don't overflow

    // Constrain h so that within the loop, src[i] accesses stay within bounds
    // Maximum index used in src: up to src[16] relative to base pointer
    // Each iteration advances src by srcStride, so last row uses src + (h-1)*srcStride + 16
    int max_src_offset = 17;  // indices 0..16 -> 17 elements
    int max_rows_by_src = (TOTAL_ELEMENTS - max_src_offset) / srcStride;
    h = h < max_rows_by_src ? h : max_rows_by_src;

    int max_dst_offset = 16;  // indices 0..15
    int max_rows_by_dst = (TOTAL_ELEMENTS - max_dst_offset) / dstStride;
    h = h < max_rows_by_dst ? h : max_rows_by_dst;

    // Initialize pointers to middle of arrays to allow some leeway on both ends
    // but ensure sufficient space after for all loads/stores
    size_t src_base = 0;
    size_t dst_base = 0;

    src = &internal_src[src_base];
    dst = &internal_dst[dst_base];

    cm = internal_cm;

    // Initialize cm lookup table
    for (int idx = 0; idx < 256; idx++) {
        cm[idx] = (uint8_t)(idx & 0xFF);
    }

    // Initialize src with non-zero data to avoid division-by-zero or degenerate cases
    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        internal_src[i] = (uint8_t)((i * 17) % 251);
    }

    // Zero-initialize dst
    memset(internal_dst, 0, TOTAL_ELEMENTS);
}
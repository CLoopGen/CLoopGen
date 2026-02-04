#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024)

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
uint8_t *cm;
int w;
int i;

void init_vars() {
    const int height = 8;
    const int extra_rows = 9; // We access up to src[8 * srcStride], so need 9 rows of source
    const int total_src_size = (extra_rows + height) * ARRAY_SIZE;
    const int total_dst_size = (height + 1) * ARRAY_SIZE; // +1 due to dst++ increment

    uint8_t *src_base = aligned_alloc(32, total_src_size * sizeof(uint8_t));
    uint8_t *dst_base = aligned_alloc(32, total_dst_size * sizeof(uint8_t));
    uint8_t *cm_base = aligned_alloc(32, 256 * sizeof(uint8_t));

    if (!src_base || !dst_base || !cm_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize cm with identity mapping in valid range
    for (int idx = 0; idx < 256; idx++) {
        cm_base[idx] = (uint8_t)idx;
    }

    // Initialize src and dst with predictable values
    for (int idx = 0; idx < total_src_size; idx++) {
        src_base[idx] = (uint8_t)(idx % 251);
    }
    for (int idx = 0; idx < total_dst_size; idx++) {
        dst_base[idx] = 0;
    }

    // Set strides and dimensions
    srcStride = ARRAY_SIZE;
    dstStride = ARRAY_SIZE;
    w = ARRAY_SIZE;

    // Assign global pointers
    src = src_base;
    dst = dst_base;
    cm = cm_base;
}
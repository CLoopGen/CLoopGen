#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to target ~0.01s runtime
#define TMP_EXTRA 11  // Need tmp[-2] to tmp[10], so we need at least 13 extra elements before and after

static uint8_t dst_data[DATA_SIZE];
static uint8_t src2_data[DATA_SIZE];
static int16_t tmp_data[DATA_SIZE / sizeof(int16_t) + 2 * TMP_EXTRA];
static uint8_t cm_data[1024];  // cm maps 10-bit shifted values, so size 1024 is safe

void init_vars() {
    // Initialize strides
    dstStride = 1;
    srcStride = 1;

    // Set width to process approximately DATA_SIZE elements in total
    w = DATA_SIZE / 8;  // Each loop iteration writes 8 bytes to dst

    // Clamp w to ensure we don't overflow any buffer
    if (w > (int)(DATA_SIZE / 8)) w = DATA_SIZE / 8;
    if (w > (int)((DATA_SIZE / sizeof(int16_t)) - 2 * TMP_EXTRA)) {
        w = (DATA_SIZE / sizeof(int16_t)) - 2 * TMP_EXTRA;
    }

    // Ensure w is positive and within bounds
    if (w <= 0) w = 1;

    // Assign pointers with proper offsets
    dst = dst_data;
    src2 = src2_data;
    tmp = tmp_data + TMP_EXTRA;  // Leave room for tmp[-2] to tmp[10]
    cm = cm_data;

    // Initialize cm lookup table (example: identity mapping with clipping)
    for (int idx = 0; idx < 1024; idx++) {
        cm_data[idx] = (uint8_t)((idx > 255) ? 255 : idx);
    }

    // Initialize src2 and tmp with non-zero data to avoid division-by-zero or undefined behavior in computation
    for (int idx = 0; idx < w + 8; idx++) {
        if (idx < w) {
            src2_data[idx] = (uint8_t)(idx & 0xFF);
        }
    }

    for (int idx = 0; idx < w + 11; idx++) {
        tmp_data[TMP_EXTRA - 2 + idx] = (int16_t)(idx & 0x3FF);  // Fill from tmp[-2] onward
    }

    // Initialize dst to zero
    memset(dst_data, 0, DATA_SIZE);

    // Initialize i
    i = 0;
}
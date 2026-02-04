#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of total data

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int C1;
int C2;
int w;
uint8_t *cm;
int i;

static uint8_t *src_base;
static uint8_t *dst_base;
static uint8_t *cm_table;

void init_vars() {
    // Initialize constants
    C1 = 13; // example coefficient
    C2 = 27; // example coefficient
    srcStride = 16;
    dstStride = 16;
    w = DATA_SIZE / (9 * sizeof(uint8_t)); // Adjust w so we stay within bounds

    // Clamp w to a reasonable range to avoid overstepping
    if (w > 8192) {
        w = 8192;
    }

    // Allocate source buffer with padding for [-1] and [9] offsets
    int src_height = w + 10; // need indices from -1 to 9 relative to each step
    size_t src_size = src_height * srcStride * sizeof(uint8_t);
    src_base = (uint8_t*)aligned_alloc(32, src_size);
    if (!src_base) exit(1);

    // Point src to start at index 0 (so -1 is valid)
    src = src_base + srcStride;

    // Allocate destination buffer with enough rows
    size_t dst_size = w * dstStride * sizeof(uint8_t);
    dst_base = (uint8_t*)aligned_alloc(32, dst_size);
    if (!dst_base) exit(1);
    dst = dst_base;

    // Allocate and initialize cm lookup table (256 entries typical for clipping)
    cm_table = (uint8_t*)malloc(256 * sizeof(uint8_t));
    if (!cm_table) exit(1);
    for (int j = 0; j < 256; j++) {
        cm_table[j] = (uint8_t)((j < 0) ? 0 : (j > 255) ? 255 : j);
    }
    cm = cm_table;

    // Initialize src data
    for (int j = 0; j < src_height; j++) {
        for (int k = 0; k < srcStride; k++) {
            src_base[j * srcStride + k] = rand() & 0xFF;
        }
    }

    // Ensure cm table covers possible input range after shift
    for (int j = 0; j < 256; j++) {
        cm_table[j] = (uint8_t)j;
    }
}
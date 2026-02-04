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

#define DATA_SIZE (1 << 20)  // ~1MB of working data

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src2[DATA_SIZE];
static int16_t internal_tmp[DATA_SIZE / sizeof(int16_t)];
static uint8_t internal_cm[1024];

void init_vars() {
    const int block_height = 8;
    const int block_width = 8;
    
    dstStride = block_height;
    srcStride = block_height;
    w = 64;  // number of iterations to process
    
    // Ensure tmp access from -16 to (w + 10)*8 does not go out of bounds
    // We need at least: 16 (for negative offset) + w + 11*8 = ~ (w+128) indices
    const int min_tmp_size = (w + 128);
    if (min_tmp_size * 8 > DATA_SIZE / sizeof(int16_t)) {
        fprintf(stderr, "Internal error: tmp buffer too small\n");
        exit(1);
    }

    dst = internal_dst;
    src2 = internal_src2;
    tmp = internal_tmp + 16;  // shift base so that [-16..] is valid
    cm = internal_cm;

    // Initialize cm lookup table (0-1023 range)
    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = (uint8_t)((idx * 17) % 256);  // arbitrary but valid mapping
    }

    // Initialize dst and src2 with non-zero values
    for (int j = 0; j < block_height * w; j++) {
        dst[j] = j % 256;
        src2[j] = (j + 42) % 256;
    }

    // Initialize tmp array with safe values
    for (int j = 0; j < min_tmp_size; j++) {
        tmp[j * 8] = (j % 100) - 50;
    }
}
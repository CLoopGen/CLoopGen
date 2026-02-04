#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure ~0.01s runtime on modern CPU

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src2[DATA_SIZE];
static int16_t internal_tmp[DATA_SIZE / sizeof(int16_t)];
static uint8_t internal_cm[1024];

void init_vars() {
    const size_t tmp_elements = DATA_SIZE / sizeof(int16_t);
    const int max_w = (tmp_elements - 10 * 8) / 8; // Ensure tmp[-2*8] to tmp[10*8] and tmp++ over w iterations stays in bounds
    const int effective_w = max_w > 0 ? max_w : 1;

    dstStride = 1;
    srcStride = 1;
    w = effective_w;
    i = 0;

    // Initialize pointers to center of buffers to allow negative indexing where needed
    tmp = internal_tmp + 2 * 8; // Allow tmp[-2*8]
    dst = internal_dst;
    src2 = internal_src2;
    cm = internal_cm;

    // Initialize cm with identity-like mapping to avoid out-of-bounds access
    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = (uint8_t)((idx * 255) / 1023); // Linear map [0,1023] -> [0,255]
    }

    // Initialize tmp with non-zero values to make computation meaningful
    for (size_t idx = 0; idx < tmp_elements; idx++) {
        internal_tmp[idx] = (int16_t)(rand() % 512 - 256);
    }

    // Initialize src2
    for (int idx = 0; idx < w; idx++) {
        src2[idx * srcStride] = (uint8_t)(rand() % 256);
    }
}
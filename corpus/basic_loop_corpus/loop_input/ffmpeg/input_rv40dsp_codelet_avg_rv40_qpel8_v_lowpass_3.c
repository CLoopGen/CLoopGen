#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int C1;
int C2;
int SHIFT;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t internal_dst[TOTAL_ELEMENTS];
static uint8_t internal_src[TOTAL_ELEMENTS + 20 * 1024]; // Extra padding for negative/positive strides
static uint8_t internal_cm[1 << 16];

void init_vars() {
    dstStride = 1;
    srcStride = 1;
    w = 10000;
    C1 = 20;
    C2 = 10;
    SHIFT = 8;

    // Initialize cm with identity-like mapping in range [0, 255]
    for (int idx = 0; idx < (1 << 16); idx++) {
        int val = (idx - (1 << (SHIFT - 1))) >> (SHIFT - 8);
        internal_cm[idx] = (val < 0) ? 0 : (val > 255) ? 255 : (uint8_t)val;
    }

    // Initialize src and dst arrays with non-zero values to avoid trivial optimizations
    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        internal_dst[idx] = (uint8_t)(idx % 256);
    }
    for (int idx = 0; idx < TOTAL_ELEMENTS + 20 * 1024; idx++) {
        internal_src[idx] = (uint8_t)((idx * 7) % 256);
    }

    // Set global pointers to point into internal buffers with safe offsets
    src = internal_src + 10 * 1024; // Offset to allow [-10*srcStride] access safely
    dst = internal_dst;

    cm = internal_cm;
}
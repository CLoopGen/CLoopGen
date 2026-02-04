#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
uint8_t *cm;
int w;
int i;

#define DATA_SIZE (16 * 1024 * 1024) // ~16MB of data to target ~0.01s runtime

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_cm[512]; // cm is used as a lookup table with index derived from computation

void init_vars() {
    // Initialize parameters
    w = 8192; // Number of iterations to ensure sufficient work without excessive memory
    dstStride = 1;
    srcStride = 1;

    // Ensure that src has at least 9 rows of data accessible via src[x * srcStride]
    // With srcStride=1, we need at least w + 8 elements in usable region
    if (w + 8 > DATA_SIZE) {
        w = DATA_SIZE - 8;
    }

    // Point to internal buffers
    dst = internal_dst;
    src = internal_src;
    cm = internal_cm;

    // Initialize src with non-zero test pattern
    for (int j = 0; j < DATA_SIZE; j++) {
        src[j] = (uint8_t)(j & 0xFF);
    }

    // Initialize cm lookup table: clamp computed index to [0,255] range
    for (int j = 0; j < 512; j++) {
        cm[j] = (uint8_t)(j < 256 ? j : 255);
    }

    // Initialize loop index
    i = 0;
}
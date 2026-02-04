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

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of input data for sufficient runtime

static uint8_t internal_dst[DATA_SIZE + 16];
static uint8_t internal_src[DATA_SIZE + 20];
static uint8_t internal_cm[256];

void init_vars() {
    // Initialize strides
    dstStride = 1;
    srcStride = 1;

    // Set width to process most of the buffer while ensuring no out-of-bounds access
    w = DATA_SIZE - 10; // ensures src[-2] to src[10] are valid for all iterations

    // Initialize pointers to center of buffers to allow required negative/positive indexing
    src = &internal_src[10]; // allows [-2..10] offset access
    dst = &internal_dst[2];  // allows [0..7] offset write

    // Initialize cm lookup table with identity mapping
    for (int idx = 0; idx < 256; idx++) {
        internal_cm[idx] = (uint8_t)idx;
    }
    cm = internal_cm;

    // Initialize src with non-zero test pattern
    for (size_t j = 0; j < sizeof(internal_src); j++) {
        internal_src[j] = (uint8_t)(j * 17 + 31);
    }

    // Zero destination
    memset(internal_dst, 0, sizeof(internal_dst));

    // Initialize loop index
    i = 0;
}
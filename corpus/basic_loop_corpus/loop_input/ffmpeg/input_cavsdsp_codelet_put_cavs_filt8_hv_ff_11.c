#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src2[DATA_SIZE];
static int16_t internal_tmp[DATA_SIZE / sizeof(int16_t)];
static uint8_t internal_cm[1024];

void init_vars() {
    dstStride = 1;
    srcStride = 1;
    w = (DATA_SIZE - 8 * 8) / (sizeof(int16_t) * 8); // ensure no out-of-bounds access
    if (w > (DATA_SIZE / 8)) w = DATA_SIZE / 8;

    dst = internal_dst;
    src2 = internal_src2;
    tmp = internal_tmp + 10 * 8; // offset to allow negative indexing from -2*8 to positive indices up to w+7*8
    cm = internal_cm;

    for (int j = 0; j < DATA_SIZE; j++) {
        internal_dst[j] = rand() % 256;
        internal_src2[j] = rand() % 256;
    }
    for (int j = 0; j < DATA_SIZE / sizeof(int16_t); j++) {
        internal_tmp[j] = rand() % 256 - 128;
    }
    for (int j = 0; j < 1024; j++) {
        internal_cm[j] = j < 0 ? 0 : (j > 255 ? 255 : j);
    }
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

static uint8_t *internal_src;
static uint8_t *internal_dst;
static uint8_t *internal_cm;

void init_vars() {
    w = 1024;
    h = 1024;
    srcStride = w + 2;
    dstStride = w;

    internal_src = (uint8_t*)aligned_alloc(32, (size_t)(h + 2) * srcStride * sizeof(uint8_t));
    internal_dst = (uint8_t*)aligned_alloc(32, (size_t)h * dstStride * sizeof(uint8_t));
    internal_cm = (uint8_t*)aligned_alloc(32, 256 * sizeof(uint8_t));

    src = internal_src + srcStride * 1 + 1;
    dst = internal_dst;
    cm = internal_cm;

    for (int idx = 0; idx < (h + 2) * srcStride; ++idx) {
        internal_src[idx] = rand() & 0xFF;
    }
    for (int idx = 0; idx < h * dstStride; ++idx) {
        internal_dst[idx] = 0;
    }
    for (int idx = 0; idx < 256; ++idx) {
        internal_cm[idx] = rand() & 0xFF;
    }
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}
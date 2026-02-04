#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define TOTAL_PIXELS (1 << 20)
#define W_VALUE 64
#define H_VALUE (TOTAL_PIXELS / W_VALUE)

static uint8_t *internal_dst;
static int16_t *internal_tmp;
static uint8_t *internal_cm;

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

void init_vars() {
    w = W_VALUE;
    dstStride = 1;

    internal_dst = aligned_alloc(64, (H_VALUE + 16) * dstStride);
    internal_tmp = aligned_alloc(64, (W_VALUE + 20) * 8 * sizeof(int16_t));
    internal_cm = calloc(1024, sizeof(uint8_t));

    dst = internal_dst + 8 * dstStride;
    tmp = internal_tmp + 10 * 8;

    for (int idx = 0; idx < (H_VALUE + 16) * dstStride; idx++) {
        internal_dst[idx] = (uint8_t)(idx % 256);
    }
    for (int idx = 0; idx < (W_VALUE + 20) * 8; idx++) {
        internal_tmp[idx] = (int16_t)((idx % 512) - 256);
    }
    for (int idx = 0; idx < 1024; idx++) {
        internal_cm[idx] = (uint8_t)(idx < 0 ? 0 : (idx > 255 ? 255 : idx));
    }

    cm = internal_cm;
}

__attribute__((destructor))
static void cleanup() {
    free(internal_dst);
    free(internal_tmp);
    free(internal_cm);
}
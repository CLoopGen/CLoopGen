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

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int16_t))
#define TMP_OFFSET 10
#define STRIDE 8

void init_vars() {
    const int max_w = (TOTAL_ELEMENTS - TMP_OFFSET * 8 - 8) / 8;
    w = max_w > 0 ? max_w : 1000;

    dstStride = STRIDE;
    srcStride = STRIDE;

    cm = aligned_alloc(32, 512 * sizeof(uint8_t));
    dst = aligned_alloc(32, w * dstStride * sizeof(uint8_t));
    src2 = aligned_alloc(32, w * srcStride * sizeof(uint8_t));
    tmp = aligned_alloc(32, (w + TMP_OFFSET + 11) * 8 * sizeof(int16_t));

    if (!cm || !dst || !src2 || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 512; idx++) {
        cm[idx] = (uint8_t)((idx * 73) % 256);
    }

    for (int idx = 0; idx < w * dstStride; idx++) {
        dst[idx] = (uint8_t)(idx % 256);
    }

    for (int idx = 0; idx < w * srcStride; idx++) {
        src2[idx] = (uint8_t)((idx * 13) % 256);
    }

    for (int idx = 0; idx < (w + TMP_OFFSET + 11) * 8; idx++) {
        tmp[idx] = (int16_t)((idx - (idx % 8)) % 256 - 128);
    }

    i = 0;
}
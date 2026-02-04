#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(uint16_t))

int32_t *tmp;
int tmpStride = 8;
int srcStride = 8;
int h = (TOTAL_ELEMENTS / 8) - 5; // ensures i < h+5 doesn't overflow
int pad = 10;
int i;

uint16_t *src;

void init_vars() {
    size_t total_src_elements = (h + 5) * srcStride + 12; // need up to src[i*srcStride + 10]
    size_t total_tmp_elements = (h + 5) * tmpStride;

    src = aligned_alloc(32, total_src_elements * sizeof(uint16_t));
    tmp = aligned_alloc(32, total_tmp_elements * sizeof(int32_t));

    for (size_t idx = 0; idx < total_src_elements; idx++) {
        src[idx] = (uint16_t)(idx % 1000);
    }

    for (size_t idx = 0; idx < total_tmp_elements; idx++) {
        tmp[idx] = 0;
    }
}
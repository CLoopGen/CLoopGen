#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64

static size_t total_data_size = DATA_SIZE_MB * 1024 * 1024;

int16_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    pad = 10;

    tmpStride = 8;
    srcStride = 7;

    h = (total_data_size / sizeof(uint16_t)) / srcStride - 5;

    if (h <= 0) {
        h = 1000;
    }

    size_t tmp_elements = (h + 5) * tmpStride;
    size_t src_elements = (h + 5) * srcStride + 8;

    tmp = aligned_alloc(32, tmp_elements * sizeof(int16_t));
    src = aligned_alloc(32, src_elements * sizeof(uint16_t));

    if (!tmp || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < tmp_elements; idx++) {
        tmp[idx] = 0;
    }
    for (size_t idx = 0; idx < src_elements; idx++) {
        src[idx] = (uint16_t)(idx % 1000);
    }
}
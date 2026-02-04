#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

int32_t *tmp;
uint16_t *src;
int tmpStride = 8;
int srcStride = 8;
int h = (TOTAL_ELEMENTS / 8) - 5; // ensures i < h + 5 doesn't overflow src
int pad = 10;
int i;

void init_vars() {
    size_t total_src_size = TOTAL_ELEMENTS * sizeof(uint16_t);
    size_t total_tmp_size = (h + 5) * tmpStride * sizeof(int32_t);

    src = (uint16_t*)aligned_alloc(32, total_src_size);
    tmp = (int32_t*)aligned_alloc(32, total_tmp_size);

    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        src[idx] = (uint16_t)(idx % 1000);
    }

    for (int i = 0; i < (h + 5) * tmpStride; ++i) {
        tmp[i] = 0;
    }
}
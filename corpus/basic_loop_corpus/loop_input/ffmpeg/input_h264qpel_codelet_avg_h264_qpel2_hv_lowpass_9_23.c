#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint16_t *src;

void init_vars() {
    h = 1000;
    pad = 10;
    srcStride = 8;
    tmpStride = 8;

    size_t total_src_elements = (h + 5) * srcStride;
    size_t total_tmp_elements = (h + 5) * tmpStride;

    src = (uint16_t*)aligned_alloc(32, total_src_elements * sizeof(uint16_t));
    tmp = (int16_t*)aligned_alloc(32, total_tmp_elements * sizeof(int16_t));

    for (size_t idx = 0; idx < total_src_elements; idx++) {
        src[idx] = (uint16_t)(idx % 1024);
    }

    for (size_t idx = 0; idx < total_tmp_elements; idx++) {
        tmp[idx] = 0;
    }
}
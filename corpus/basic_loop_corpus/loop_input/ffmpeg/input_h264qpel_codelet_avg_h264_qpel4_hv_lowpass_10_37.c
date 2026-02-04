#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint16_t)
#define ARRAY_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

int16_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    const int width = 256;
    h = (ARRAY_ELEMENTS / width) - 5; 
    if (h <= 0) {
        h = 1000;
    }
    srcStride = width;
    tmpStride = width;
    pad = 10;

    size_t src_size = (size_t)(h + 5) * srcStride * sizeof(uint16_t);
    size_t tmp_size = (size_t)(h + 5) * tmpStride * sizeof(int16_t);

    src = aligned_alloc(32, src_size);
    tmp = aligned_alloc(32, tmp_size);

    for (size_t idx = 0; idx < src_size / sizeof(uint16_t); idx++) {
        src[idx] = (uint16_t)(idx % 1024);
    }
    for (size_t idx = 0; idx < tmp_size / sizeof(int16_t); idx++) {
        tmp[idx] = 0;
    }
}
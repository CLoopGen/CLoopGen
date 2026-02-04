#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 256;
int width = 1024;
int x, y;

int8_t *filter;
int16_t *tmp;
int16_t *dst;

void init_vars() {
    const int filter_size = 4;
    const int tmp_width = 4096;
    const int tmp_height = 512;
    const size_t tmp_size = tmp_width * tmp_height;
    const size_t dst_size = tmp_size;

    filter = (int8_t*)aligned_alloc(32, filter_size * sizeof(int8_t));
    tmp = (int16_t*)aligned_alloc(32, tmp_size * sizeof(int16_t));
    dst = (int16_t*)aligned_alloc(32, dst_size * sizeof(int16_t));

    for (int i = 0; i < filter_size; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    for (size_t i = 0; i < tmp_size; i++) {
        tmp[i] = (int16_t)(i % 256);
    }

    for (size_t i = 0; i < dst_size; i++) {
        dst[i] = 0;
    }
}
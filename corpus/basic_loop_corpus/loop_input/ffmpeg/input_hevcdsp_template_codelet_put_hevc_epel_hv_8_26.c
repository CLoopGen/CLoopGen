#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t *filter;
int16_t *tmp;
int16_t *dst;

void init_vars() {
    filter = (int8_t*)aligned_alloc(64, 4 * sizeof(int8_t));
    tmp = (int16_t*)aligned_alloc(64, (width + 2 * 64) * height * sizeof(int16_t) + 128 * sizeof(int16_t));
    dst = (int16_t*)aligned_alloc(64, width * height * sizeof(int16_t));

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    size_t total_tmp_size = (width + 2 * 64) * height + 128;
    for (size_t i = 0; i < total_tmp_size; i++) {
        tmp[i] = (int16_t)(i % 512);
    }

    for (int i = 0; i < width * height; i++) {
        dst[i] = 0;
    }
}
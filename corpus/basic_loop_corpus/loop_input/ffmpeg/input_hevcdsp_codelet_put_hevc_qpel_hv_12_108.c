#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x, y;

int8_t *filter;
int16_t *tmp;
int16_t *dst;

void init_vars() {
    filter = (int8_t*)aligned_alloc(32, 8 * sizeof(int8_t));
    tmp = (int16_t*)aligned_alloc(32, (width + 4 * 64) * height * sizeof(int16_t) + 8 * 64 * sizeof(int16_t));
    dst = (int16_t*)aligned_alloc(32, width * height * sizeof(int16_t));

    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i - 3);
    }

    size_t total_tmp_size = (width + 4 * 64) * height + 8 * 64;
    for (size_t i = 0; i < total_tmp_size; i++) {
        tmp[i] = (int16_t)(rand() % 100);
    }

    for (int i = 0; i < width * height; i++) {
        dst[i] = 0;
    }
}
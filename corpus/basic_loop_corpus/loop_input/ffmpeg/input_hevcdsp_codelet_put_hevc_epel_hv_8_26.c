#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 128;
int x;
int y;

int8_t *filter;
int16_t *dst;
int16_t *tmp;

void init_vars() {
    filter = (int8_t*)aligned_alloc(32, sizeof(int8_t) * 4);
    dst = (int16_t*)aligned_alloc(32, sizeof(int16_t) * 64 * height * 2);
    tmp = (int16_t*)aligned_alloc(32, sizeof(int16_t) * (64 * height + 192));

    if (!filter || !dst || !tmp) {
        exit(1);
    }

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    size_t total_tmp_size = 64 * height + 192;
    for (size_t i = 0; i < total_tmp_size; i++) {
        tmp[i] = (int16_t)(i % 512);
    }

    for (int i = 0; i < 64 * height * 2; i++) {
        dst[i] = 0;
    }
}
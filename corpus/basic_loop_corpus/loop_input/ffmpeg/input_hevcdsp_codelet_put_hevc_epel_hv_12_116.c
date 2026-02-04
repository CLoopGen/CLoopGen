#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x, y;

int8_t *filter;
int16_t *dst;
int16_t *tmp;

void init_vars() {
    filter = (int8_t*)aligned_alloc(32, 4 * sizeof(int8_t));
    dst = (int16_t*)aligned_alloc(32, height * width * sizeof(int16_t));
    tmp = (int16_t*)aligned_alloc(32, (width + 2 * 64) * height * sizeof(int16_t));

    for (int i = 0; i < 4; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    ptrdiff_t offset = 64;
    int16_t* tmp_base = tmp + offset;
    tmp = tmp_base;

    for (int i = 0; i < height * (width + 2 * 64); i++) {
        ((int16_t*)tmp_base)[-offset + i] = (int16_t)(i % 256);
    }

    for (int i = 0; i < height * width; i++) {
        dst[i] = 0;
    }
}
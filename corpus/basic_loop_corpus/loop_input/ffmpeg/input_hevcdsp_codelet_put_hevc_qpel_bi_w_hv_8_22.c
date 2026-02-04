#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {16, -8, 4, -2, 1, -2, 4, -8};
int8_t *filter = filter_data;

uint8_t *src;
ptrdiff_t srcstride = 1024;

int16_t *tmp;

void init_vars() {
    size_t src_size = (height + 7) * srcstride;
    src = aligned_alloc(64, src_size);
    tmp = aligned_alloc(64, (width + 63) * sizeof(int16_t) * (height + 7));

    for (size_t i = 0; i < src_size; i++) {
        src[i] = rand() % 256;
    }

    for (size_t i = 0; i < (width + 63) * sizeof(int16_t) * (height + 7) / sizeof(int16_t); i++) {
        tmp[i] = 0;
    }
}
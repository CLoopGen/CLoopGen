#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, -3, 5, -7, 7, -5, 3, -1};
int8_t *filter = filter_data;

uint8_t *src;
ptrdiff_t srcstride = 1024;

int16_t *tmp;

void init_vars() {
    size_t src_size = (height + 7) * srcstride;
    src = (uint8_t*)aligned_alloc(64, src_size);
    tmp = (int16_t*)aligned_alloc(64, (width + 64) * sizeof(int16_t) * (height + 7));

    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src[i] = rand() & 0xFF;
    }

    for (int i = 0; i < width + 64; i++) {
        tmp[i] = 0;
    }
}
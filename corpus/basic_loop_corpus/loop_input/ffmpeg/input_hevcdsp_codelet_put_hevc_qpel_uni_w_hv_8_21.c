#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, -2, 3, -4, 4, -3, 2, -1};
int8_t *filter = filter_data;

uint8_t *src;
ptrdiff_t srcstride = 1024;

int16_t *tmp;

void init_vars() {
    size_t src_size = (height + 7) * srcstride;
    src = aligned_alloc(64, src_size);
    size_t tmp_size = (width + 64) * ((height + 7) + 1); 
    tmp = aligned_alloc(64, tmp_size);

    for (size_t i = 0; i < src_size; i++) {
        src[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < tmp_size / sizeof(int16_t); i++) {
        ((int16_t*)tmp)[i] = 0;
    }
}
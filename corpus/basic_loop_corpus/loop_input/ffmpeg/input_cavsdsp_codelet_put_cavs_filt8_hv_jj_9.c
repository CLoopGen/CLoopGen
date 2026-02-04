#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

uint8_t *dst_base;
int16_t *tmp_base;
uint8_t cm_data[256];

void init_vars() {
    const int width = 1920;
    const int height = 1080;
    w = width;
    dstStride = height;

    dst_base = (uint8_t*)aligned_alloc(32, (size_t)width * height * sizeof(uint8_t));
    dst = dst_base;

    tmp_base = (int16_t*)aligned_alloc(32, (size_t)(width + 12) * 8 * sizeof(int16_t));
    tmp = tmp_base + 2 * 8; 

    for (int idx = 0; idx < (width + 12) * 8; idx++) {
        tmp_base[idx] = (int16_t)(rand() % 512 - 256);
    }

    for (int idx = 0; idx < 256; idx++) {
        cm_data[idx] = (uint8_t)(idx & 255);
    }
    cm = cm_data;
}
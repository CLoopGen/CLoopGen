#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int height;
int width;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride;
int8_t *filter;

static uint16_t *src_data;
static int16_t *dst_data;
static int8_t filter_data[8];

void init_vars() {
    width = 64;
    height = 1024;
    srcstride = 64;

    size_t src_size = (height + 7) * srcstride * sizeof(uint16_t);
    src_data = aligned_alloc(32, src_size);
    dst_data = aligned_alloc(32, height * 64 * sizeof(int16_t));
    dst = dst_data;
    src = src_data + 3 * srcstride;
    filter = filter_data;

    for (int i = 0; i < 8; i++) {
        filter_data[i] = (int8_t)(i * 16);
    }

    for (size_t i = 0; i < (height + 7) * srcstride; i++) {
        src_data[i] = (uint16_t)(i % 512);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            dst_data[i * 64 + j] = 0;
        }
    }
}
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

static uint16_t src_data[256 * 1024]; // ~512KB input
static int16_t dst_data[256 * 1024];
static int8_t filter_data[4] = {1, 2, 1, 0}; // example filter coefficients

void init_vars() {
    height = 512;
    width = 500;
    srcstride = 512;

    src = src_data;
    dst = dst_data;
    filter = filter_data;

    for (int i = 0; i < (int)(sizeof(src_data) / sizeof(src_data[0])); ++i) {
        src_data[i] = rand() & 0xFFFF;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *dst;
uint8_t *src;
int src_size;
int width;
int height;
int linesize;
int16_t *tvdc;
int x;
int y;
int plane;
int8_t pixel;
int i;
int j;

void init_vars() {
    width = 1920;
    height = 1080;
    linesize = width * 4;
    src_size = (1 << 20); // ~1MB of source data
    pixel = 128;
    x = 0;
    y = 0;
    plane = 0;
    i = 0;
    j = 0;

    dst = aligned_alloc(32, (size_t)linesize * height);
    src = malloc((size_t)src_size);
    tvdc = aligned_alloc(32, 16 * sizeof(int16_t));

    memset(dst, 0, (size_t)linesize * height);
    for (int idx = 0; idx < src_size; idx++) {
        src[idx] = rand() & 255;
    }
    for (int idx = 0; idx < 16; idx++) {
        tvdc[idx] = (rand() % 3) - 1;
    }
}
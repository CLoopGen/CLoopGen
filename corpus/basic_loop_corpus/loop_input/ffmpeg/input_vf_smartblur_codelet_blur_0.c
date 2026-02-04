#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_linesize;
uint8_t *src;
int src_linesize;
int w;
int h;
int threshold;
int x;
int y;
int orig;
int filtered;
int diff;

void init_vars() {
    w = 2048;
    h = 128;
    threshold = 10;

    src_linesize = w;
    dst_linesize = w;

    src = (uint8_t*)aligned_alloc(32, (size_t)h * src_linesize);
    dst = (uint8_t*)aligned_alloc(32, (size_t)h * dst_linesize);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            src[j + i * src_linesize] = (uint8_t)((i * 7 + j * 13) % 256);
            dst[j + i * dst_linesize] = (uint8_t)((i * 7 + j * 13 + 15) % 256);
        }
    }

    x = 0;
    y = 0;
    orig = 0;
    filtered = 0;
    diff = 0;
}
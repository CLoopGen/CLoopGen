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
    h = 1024;
    src_linesize = w;
    dst_linesize = w;
    threshold = 10;

    src = (uint8_t*)malloc(h * src_linesize * sizeof(uint8_t));
    dst = (uint8_t*)malloc(h * dst_linesize * sizeof(uint8_t));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            src[j + i * src_linesize] = (uint8_t)((i * 73 + j * 101) % 256);
            dst[j + i * dst_linesize] = (uint8_t)((i * 53 + j * 131) % 256);
        }
    }

    x = 0;
    y = 0;
    orig = 0;
    filtered = 0;
    diff = 0;
}
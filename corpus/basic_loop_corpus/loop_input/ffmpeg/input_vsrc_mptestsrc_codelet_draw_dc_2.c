#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int dst_linesize;
int color;
int w;
int h;
int x;
int y;

void init_vars() {
    w = 4096;
    h = 4096;
    dst_linesize = w;
    color = 128;
    dst = (uint8_t*)aligned_alloc(32, (size_t)h * dst_linesize);
}
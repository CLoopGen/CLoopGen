#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define FILTER_SIZE 6
#define CM_SIZE 256
#define HEIGHT_FACTOR 1000
#define WIDTH 4

void init_vars() {
    h = HEIGHT_FACTOR;
    dststride = 16;
    srcstride = 16;

    filter = aligned_alloc(32, sizeof(uint8_t) * FILTER_SIZE);
    cm = aligned_alloc(32, sizeof(uint8_t) * CM_SIZE);

    for (int i = 0; i < FILTER_SIZE; i++) {
        filter[i] = (i + 1) * 10;
    }

    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = i;
    }

    size_t src_size = (h + 2) * srcstride;
    size_t dst_size = h * dststride;

    src = aligned_alloc(32, src_size);
    dst = aligned_alloc(32, dst_size);

    memset(src, 128, src_size);
    memset(dst, 0, dst_size);

    x = 0;
    y = 0;
}
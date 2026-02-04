#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint16_t *filter;
int filt_w = 5;
uint16_t *dst;
int w = 1024;
int h = 1024;
uint16_t *src;
ptrdiff_t src_stride = 1024;
ptrdiff_t dst_stride = 1024;
int radius = 2;
int borders_bottom = 0;
int i;
int j;
int k;
int sum;

void init_vars() {
    const size_t src_size = (size_t)h * src_stride;
    const size_t dst_size = (size_t)h * dst_stride;
    const size_t filter_size = filt_w;

    src = aligned_alloc(32, src_size * sizeof(uint16_t));
    dst = aligned_alloc(32, dst_size * sizeof(uint16_t));
    filter = aligned_alloc(32, filter_size * sizeof(uint16_t));

    if (!src || !dst || !filter) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)(time(NULL)));
    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = rand() & 0x3FF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst[idx] = 0;
    }
    int total = 0;
    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = (rand() % 1024) + 100;
        total += filter[idx];
    }
    int shift = 10;
    for (int idx = 0; idx < filt_w; idx++) {
        filter[idx] = (uint16_t)((filter[idx] << shift) / total);
    }

    w = 1024;
    h = 1024;
    filt_w = 5;
    radius = 2;
    borders_bottom = 0;
    src_stride = 1024;
    dst_stride = 1024;
}
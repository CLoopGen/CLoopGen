#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

static uint16_t *top_data;
static uint16_t *bottom_data;
static uint16_t *dst_data;

void init_vars() {
    width = 1024;
    height = 512;
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t top_size = (size_t)height * top_linesize;
    size_t bottom_size = (size_t)height * bottom_linesize;
    size_t dst_size = (size_t)height * dst_linesize;

    top_data = aligned_alloc(32, top_size * sizeof(uint16_t));
    bottom_data = aligned_alloc(32, bottom_size * sizeof(uint16_t));
    dst_data = aligned_alloc(32, dst_size * sizeof(uint16_t));

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (size_t idx = 0; idx < top_size; idx++) {
        top_data[idx] = rand() % 1024;
    }
    for (size_t idx = 0; idx < bottom_size; idx++) {
        bottom_data[idx] = rand() % 1024 + 1;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_data[idx] = 0;
    }
}
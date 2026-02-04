#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
    width = 2048;
    height = 128;
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(uint16_t);

    top_data = aligned_alloc(32, total_size);
    bottom_data = aligned_alloc(32, total_size);
    dst_data = aligned_alloc(32, total_size);

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = rand() % 1024;
        bottom_data[idx] = rand() % 1024;
        dst_data[idx] = 0;
    }
}
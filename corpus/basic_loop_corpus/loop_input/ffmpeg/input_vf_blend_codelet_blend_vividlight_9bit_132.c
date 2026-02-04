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

static uint16_t *top_buffer;
static uint16_t *bottom_buffer;
static uint16_t *dst_buffer;

void init_vars() {
    width = 1024;
    height = 512;
    opacity = 0.75;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(uint16_t);

    top_buffer = aligned_alloc(32, total_size);
    bottom_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!top_buffer || !bottom_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < width * height; idx++) {
        top_buffer[idx] = rand() % 512;
        bottom_buffer[idx] = rand() % 512;
        dst_buffer[idx] = 0;
    }
}
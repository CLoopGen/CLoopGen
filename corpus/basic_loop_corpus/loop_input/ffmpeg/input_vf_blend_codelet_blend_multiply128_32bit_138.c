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
float *top;
float *bottom;
float *dst;
double opacity;
int i;
int j;

static float *top_buffer;
static float *bottom_buffer;
static float *dst_buffer;

void init_vars() {
    width = 2048;
    height = 128;
    opacity = 0.75;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(float);

    top_buffer = aligned_alloc(32, total_size);
    bottom_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    top = top_buffer;
    bottom = bottom_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < width * height; idx++) {
        top_buffer[idx] = (float)(drand48());
        bottom_buffer[idx] = (float)(drand48());
        dst_buffer[idx] = 0.0f;
    }

    i = 0;
    j = 0;
}
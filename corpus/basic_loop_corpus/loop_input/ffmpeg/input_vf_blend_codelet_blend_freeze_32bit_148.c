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

static float *top_data;
static float *bottom_data;
static float *dst_data;

void init_vars() {
    width = 2048;
    height = 128;
    
    opacity = 0.5;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = width * height * sizeof(float);

    top_data = (float*)aligned_alloc(32, total_size);
    bottom_data = (float*)aligned_alloc(32, total_size);
    dst_data = (float*)aligned_alloc(32, total_size);

    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (float)(idx % 256) / 255.0f;
        bottom_data[idx] = (float)((idx + 10) % 256) / 255.0f;
        dst_data[idx] = 0.0f;
    }
}
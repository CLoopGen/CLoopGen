#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *src;
ptrdiff_t linesize;
int w;
int h;
float *histogram;
int y;
int x;

void init_vars() {
    w = 2048;
    h = 512;
    linesize = w;

    uint64_t total_elements = (uint64_t)w * h;
    uint64_t histogram_size = 65536;

    src = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    histogram = (float*)aligned_alloc(32, histogram_size * sizeof(float));

    for (uint64_t i = 0; i < total_elements; i++) {
        src[i] = rand() % histogram_size;
    }
    for (uint64_t i = 0; i < histogram_size; i++) {
        histogram[i] = 0.0f;
    }
}
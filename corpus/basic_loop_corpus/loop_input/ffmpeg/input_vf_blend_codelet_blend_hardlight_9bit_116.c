#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_SIZE_MB 64

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

void init_vars() {
    opacity = 0.75;
    height = 2048;
    width = 8192;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_elements = height * width;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    top = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom = (uint16_t*)aligned_alloc(32, total_bytes);
    dst = (uint16_t*)aligned_alloc(32, total_bytes);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = rand() % 1024;
        bottom[idx] = rand() % 1024;
    }
}
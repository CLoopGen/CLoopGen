#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_ITERATIONS 20000000

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
    width = 1024;
    height = (TOTAL_ITERATIONS + width - 1) / width;
    height = (height < 1) ? 1 : height;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_elements = width * height;

    top = aligned_alloc(32, total_elements * sizeof(uint16_t));
    bottom = aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst = aligned_alloc(32, total_elements * sizeof(uint16_t));

    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = rand() % 1024;
        bottom[idx] = rand() % 1024;
    }
}
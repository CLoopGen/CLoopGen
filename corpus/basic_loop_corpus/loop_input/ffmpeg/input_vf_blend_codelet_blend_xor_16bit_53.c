#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
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

void init_vars() {
    width = 2048;
    height = 512;
    opacity = 0.75;

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t total_size = (size_t)width * height * sizeof(uint16_t);

    top = aligned_alloc(32, total_size);
    bottom = aligned_alloc(32, total_size);
    dst = aligned_alloc(32, total_size);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
        dst[idx] = 0;
    }
}
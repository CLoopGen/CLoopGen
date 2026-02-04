#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *top;
ptrdiff_t top_linesize;
uint8_t *bottom;
ptrdiff_t bottom_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
double opacity;
int i;
int j;

void init_vars() {
    width = 1920;
    height = 1080;
    opacity = 0.5;

    top_linesize = width * sizeof(uint8_t);
    bottom_linesize = width * sizeof(uint8_t);
    dst_linesize = width * sizeof(uint8_t);

    size_t total_size = (width * height) * sizeof(uint8_t);

    top = aligned_alloc(32, total_size);
    bottom = aligned_alloc(32, total_size);
    dst = aligned_alloc(32, total_size);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        top[idx] = rand() % 256;
        bottom[idx] = rand() % 256;
        dst[idx] = 0;
    }
}
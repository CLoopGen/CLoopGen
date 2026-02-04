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

#define DATA_SIZE_MB 64

void init_vars() {
    height = 2048;
    width = 8192;

    top_linesize = width * sizeof(uint16_t);
    bottom_linesize = width * sizeof(uint16_t);
    dst_linesize = width * sizeof(uint16_t);

    size_t total_size = height * width * sizeof(uint16_t);

    top = aligned_alloc(32, total_size);
    bottom = aligned_alloc(32, total_size);
    dst = aligned_alloc(32, total_size);

    for (size_t idx = 0; idx < height * width; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
    }

    opacity = 0.5;
}

__attribute__((constructor)) void constructor_init() {
    init_vars();
}
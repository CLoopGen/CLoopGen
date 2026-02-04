#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_SIZE_MB 64

ptrdiff_t top_linesize = 1024;
ptrdiff_t bottom_linesize = 1024;
ptrdiff_t dst_linesize = 1024;
ptrdiff_t width = 1024;
ptrdiff_t height = (TOTAL_SIZE_MB * 1024 * 1024 / sizeof(uint16_t)) / 1024;

uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity = 0.5;
int i = 0;
int j = 0;

void init_vars() {
    size_t total_elements = height * top_linesize;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    top = (uint16_t*)aligned_alloc(32, total_bytes);
    bottom = (uint16_t*)aligned_alloc(32, total_bytes);
    dst = (uint16_t*)aligned_alloc(32, total_bytes);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
        dst[idx] = 0;
    }
}
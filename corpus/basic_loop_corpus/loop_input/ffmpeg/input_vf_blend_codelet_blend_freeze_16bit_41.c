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
#define ELEMENT_SIZE sizeof(uint16_t)
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

void init_vars() {
    opacity = 0.75;
    height = sqrt(TOTAL_ELEMENTS / 4);
    width = sqrt(TOTAL_ELEMENTS / 4);

    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    size_t array_size = width * height * sizeof(uint16_t);

    top = aligned_alloc(32, array_size);
    bottom = aligned_alloc(32, array_size);
    dst = aligned_alloc(32, array_size);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < width * height; idx++) {
        top[idx] = rand() % 65536;
        bottom[idx] = rand() % 65536;
        if (bottom[idx] == 0) bottom[idx] = 1;
    }

    i = 0;
    j = 0;
}
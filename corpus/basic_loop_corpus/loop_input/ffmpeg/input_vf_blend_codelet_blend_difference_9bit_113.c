#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint16_t)
#define ELEMENTS_PER_MB (1024 * 1024 / ELEMENT_SIZE)
#define NUM_ELEMENTS (TOTAL_SIZE_MB * ELEMENTS_PER_MB)

ptrdiff_t top_linesize = NUM_ELEMENTS / 4;
ptrdiff_t bottom_linesize = NUM_ELEMENTS / 4;
ptrdiff_t dst_linesize = NUM_ELEMENTS / 4;
ptrdiff_t width = NUM_ELEMENTS / 4;
ptrdiff_t height = 4;

uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity = 0.75;
int i;
int j;

void init_vars() {
    top = (uint16_t*)aligned_alloc(32, NUM_ELEMENTS * ELEMENT_SIZE);
    bottom = (uint16_t*)aligned_alloc(32, NUM_ELEMENTS * ELEMENT_SIZE);
    dst = (uint16_t*)aligned_alloc(32, NUM_ELEMENTS * ELEMENT_SIZE);

    if (!top || !bottom || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < NUM_ELEMENTS; ++idx) {
        top[idx] = (uint16_t)(idx % 65535);
        bottom[idx] = (uint16_t)((idx * 3) % 65535);
        dst[idx] = 0;
    }
}
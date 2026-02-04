#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 2048;
int h = 128;
int depth = 10;
uint16_t *dsty;
int16_t *srcy;
ptrdiff_t stridey;
int i;
int j;

void init_vars() {
    const size_t total_elements = (size_t)w * h;
    dsty = aligned_alloc(32, total_elements * sizeof(uint16_t));
    srcy = aligned_alloc(32, total_elements * sizeof(int16_t));
    stridey = w;

    for (size_t idx = 0; idx < total_elements; idx++) {
        srcy[idx] = rand() % ((1 << depth) + 100) - 50;
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        dsty[idx] = 0;
    }
}
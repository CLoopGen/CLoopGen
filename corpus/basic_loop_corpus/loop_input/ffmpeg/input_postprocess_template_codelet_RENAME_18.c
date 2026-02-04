#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t * yHistogram;
uint64_t sum;
int i;

void init_vars() {
    const size_t array_size = 256;
    yHistogram = (uint64_t*)aligned_alloc(64, array_size * sizeof(uint64_t));
    for (size_t idx = 0; idx < array_size; idx++) {
        yHistogram[idx] = idx * 31 + 1;
    }
    sum = 0;
    i = 0;
}
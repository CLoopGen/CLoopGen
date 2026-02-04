#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *histogram;
uint32_t total_windows;
int i;

void init_vars() {
    const size_t array_size = 12000;
    histogram = (uint32_t*)calloc(array_size, sizeof(uint32_t));
    if (!histogram) {
        exit(1);
    }
    for (size_t idx = 0; idx < array_size; idx++) {
        histogram[idx] = (uint32_t)(idx % 1000);
    }
    total_windows = 0;
    i = 0;
}
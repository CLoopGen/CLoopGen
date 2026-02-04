#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t ve[47];
uint8_t vo[47];

static uint8_t *alloc_left;

void init_vars() {
    size_t data_size = 1 << 20;
    alloc_left = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!alloc_left) {
        exit(1);
    }
    left = alloc_left + 1;
    for (size_t idx = 0; idx < data_size; ++idx) {
        alloc_left[idx] = (uint8_t)(idx * idx + 3 * idx + 1);
    }
    for (int j = 0; j < 47; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
    i = 0;
}
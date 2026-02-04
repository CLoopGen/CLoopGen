#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t ve[11];
uint8_t vo[11];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    left = (uint8_t*)aligned_alloc(32, data_size);
    if (!left) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        left[idx] = (uint8_t)(idx % 256);
    }

    for (int j = 0; j < 11; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
    i = 0;
}
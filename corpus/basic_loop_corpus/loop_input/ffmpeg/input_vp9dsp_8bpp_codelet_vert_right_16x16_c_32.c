#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t ve[23];
uint8_t vo[23];

void init_vars() {
    const size_t data_size = 1 << 20;
    left = (uint8_t*)aligned_alloc(32, data_size);
    if (!left) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        left[idx] = (uint8_t)(idx % 256);
    }
}
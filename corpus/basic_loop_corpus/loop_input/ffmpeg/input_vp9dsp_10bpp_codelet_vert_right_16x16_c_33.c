#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *left;
int i;
uint16_t ve[23];
uint16_t vo[23];

static size_t data_size = 1 << 17; // 128KB of uint16_t data (~256KB in bytes)

void init_vars() {
    left = (uint16_t *)aligned_alloc(_Alignof(uint16_t), data_size * sizeof(uint16_t));
    if (!left) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        left[idx] = (uint16_t)(idx % 32768);
    }

    for (int j = 0; j < 23; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
    i = 0;
}
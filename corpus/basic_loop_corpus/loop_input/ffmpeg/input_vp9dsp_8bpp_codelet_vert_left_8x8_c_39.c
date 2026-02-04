#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t ve[7];
uint8_t vo[7];

static uint8_t *allocated_top;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB to ensure ~0.01s runtime
    allocated_top = calloc(data_size, sizeof(uint8_t));
    if (!allocated_top) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        allocated_top[idx] = (uint8_t)(idx % 256);
    }

    top = allocated_top;
}
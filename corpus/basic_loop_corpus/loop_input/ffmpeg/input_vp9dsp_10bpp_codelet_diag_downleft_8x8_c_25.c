#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
int i;
uint16_t v[7];

static uint16_t *allocated_top;

void init_vars() {
    size_t data_size = 1 << 20; // ~2MB of input data (1M elements * 2 bytes)
    allocated_top = calloc(data_size, sizeof(uint16_t));
    if (!allocated_top) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        allocated_top[idx] = (uint16_t)(idx % 512);
    }

    top = allocated_top;

    i = 0;
    for (int j = 0; j < 7; ++j) {
        v[j] = 0;
    }
}
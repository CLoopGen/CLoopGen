#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t ve[47];
uint8_t vo[47];

static uint8_t *top_data;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    top_data = (uint8_t*)aligned_alloc(32, data_size);
    if (!top_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_data[idx] = rand() & 0xFF;
    }

    top = top_data;

    for (int j = 0; j < 47; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
}
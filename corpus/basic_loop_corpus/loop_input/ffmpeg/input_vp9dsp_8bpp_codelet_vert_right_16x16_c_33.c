#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t ve[23];
uint8_t vo[23];

static uint8_t *top_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    top_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!top_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_storage[idx] = (uint8_t)(idx % 256);
    }

    top = top_storage + 1; // Offset to allow access at i-1 when i=0 in loop

    for (int j = 0; j < 23; ++j) {
        ve[j] = 0;
        vo[j] = 0;
    }
}
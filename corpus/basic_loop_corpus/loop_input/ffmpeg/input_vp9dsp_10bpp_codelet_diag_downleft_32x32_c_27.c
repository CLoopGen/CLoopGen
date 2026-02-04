#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *top;
int i;
uint16_t v[31];

static uint16_t *top_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // ~2MB of input data (1M elements * 2 bytes)
    top_buffer = calloc(data_size, sizeof(uint16_t));
    if (!top_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        top_buffer[idx] = (uint16_t)(idx * idx + 31);
    }

    top = top_buffer;

    for (int j = 0; j < 31; ++j) {
        v[j] = 0;
    }
}
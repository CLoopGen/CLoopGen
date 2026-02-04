#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *cdf;
unsigned int k;
unsigned int symbol;

static uint16_t *cdf_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of data (2^20 elements)
    cdf_buffer = calloc(data_size, sizeof(uint16_t));
    if (!cdf_buffer) {
        exit(1);
    }

    // Initialize sorted CDF values to ensure valid search
    for (size_t i = 0; i < data_size - 1; i++) {
        cdf_buffer[i] = (uint16_t)(i * 2);
    }
    cdf_buffer[data_size - 1] = UINT16_MAX; // Ensure last element is max

    cdf = cdf_buffer;
    symbol = (UINT16_MAX / 2); // Set symbol to mid-range value
    k = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *left;
int i;
uint16_t v[30];

static uint16_t left_data[18]; // Size to satisfy: i+2 < 18 when i < 14 (since loop runs up to i=13)

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data
    left = aligned_alloc(32, data_size);
    if (!left) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        left[idx] = (uint16_t)(idx * 7919 % 65535); // Arbitrary prime-based pattern
    }

    // Ensure the static v array is initialized within bounds
    for (int j = 0; j < 30; j++) {
        v[j] = 0;
    }

    // Initialize i to a safe value (will be overwritten in loop)
    i = 0;
}
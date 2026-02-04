#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[62];

static uint8_t left_data[34]; // Size to accommodate index up to i+2 where i < 30 => max index 32

void init_vars() {
    // Allocate and initialize left pointer to point to heap-allocated buffer
    left = left_data;

    // Initialize left data with pseudo-random values for realistic computation
    for (int j = 0; j < 34; j++) {
        left[j] = (uint8_t)((j * 17) & 0xFF);
    }

    // Initialize v array to zero
    for (int j = 0; j < 62; j++) {
        v[j] = 0;
    }
}
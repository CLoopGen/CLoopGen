#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coeffs;
int length;
int i;
unsigned int a1;

static int32_t *coeffs_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of int32_t data
    size_t num_elements = data_size / sizeof(int32_t);

    coeffs_buffer = aligned_alloc(32, data_size);
    if (!coeffs_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        coeffs_buffer[idx] = (int32_t)(idx & 0xFF);
    }

    coeffs = coeffs_buffer;
    length = (int)(num_elements - 2); // Ensure we don't go out of bounds in loop: uses coeffs[1], steps by 2
    i = 0;
    a1 = 1000U;
}
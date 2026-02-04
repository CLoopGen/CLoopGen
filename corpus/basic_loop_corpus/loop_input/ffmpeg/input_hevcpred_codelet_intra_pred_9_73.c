#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *left;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256MB of data
    size_t num_elements = data_size / sizeof(uint16_t);

    // Ensure at least 65 elements to cover left[-1] and left[63]
    if (num_elements < 65) {
        num_elements = 65;
    }

    left = aligned_alloc(32, (num_elements) * sizeof(uint16_t));
    
    // Initialize all elements to non-zero to avoid undefined behavior in computation
    for (size_t idx = 0; idx < num_elements; idx++) {
        left[idx] = (uint16_t)(idx % 65535);
    }
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int i;
int32_t *block;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of data
    block = (int32_t*)aligned_alloc(32, data_size);
    if (!block) {
        exit(1);
    }
    const size_t num_elements = data_size / sizeof(int32_t);
    
    // Ensure we have enough elements so that i+7*8 is in bounds when i < 8
    // Maximum index accessed: i + 7*8 with i up to 7 => 7 + 56 = 63
    if (num_elements < 64) {
        exit(1);
    }

    // Initialize block with pseudo-random data for realistic computation
    for (size_t idx = 0; idx < num_elements; idx++) {
        block[idx] = (int32_t)(rand() ^ (rand() << 15));
    }

    i = 0; // Initial value for loop counter
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int32_t *block;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of data
    block = (int32_t*)aligned_alloc(32, data_size);
    if (!block) {
        exit(1);
    }

    // Initialize block with non-zero values to ensure meaningful computation
    const size_t num_elements = data_size / sizeof(int32_t);
    for (size_t idx = 0; idx < num_elements; ++idx) {
        block[idx] = (int32_t)(idx % 256);
    }
}

void loop();
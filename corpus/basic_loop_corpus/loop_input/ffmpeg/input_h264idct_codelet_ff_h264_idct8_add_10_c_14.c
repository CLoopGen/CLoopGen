#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
int32_t *block;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    block = (int32_t*)aligned_alloc(32, data_size);
    
    if (!block) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize block with pseudo-random data for realistic computation
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < data_size / sizeof(int32_t); ++idx) {
        block[idx] = (int32_t)(rand() % 1000) - 500;
    }
}
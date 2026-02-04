#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
uint32_t *src;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    src = (uint32_t *)aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }

    // Initialize array with non-zero values for meaningful computation
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < (data_size / sizeof(uint32_t)); ++idx) {
        src[idx] = (uint32_t)rand();
    }
}
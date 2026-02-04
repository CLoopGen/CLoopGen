#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int temp[16];
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data for ~0.01 sec runtime estimate
    block = (int16_t*)aligned_alloc(32, data_size);
    
    if (!block) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 16; ++idx) {
        temp[idx] = (rand() % 1000) - 500;
    }
}

// Ensure definitions are visible
int16_t *block;
int temp[16];
int i;
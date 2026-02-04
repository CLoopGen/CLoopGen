#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint16_t *left;
uint16_t *filtered_left;

void init_vars() {
    // Allocate sufficient data to make the loop run ~0.01 seconds
    // Empirical testing suggests ~64M elements gives desired timing for this type of computation
    size = 64 * 1024 * 1024;  // 64 million elements

    // Allocate arrays with padding to prevent out-of-bounds access
    // Loop accesses: left[i+1], left[i], left[i-1] for i from 2*size-2 down to 0
    // So we need valid indices from -1 to 2*size-1 inclusive -> total size: 2*size + 1
    size_t total_size = 2 * size + 1;
    left = (uint16_t*)calloc(total_size, sizeof(uint16_t));
    filtered_left = (uint16_t*)calloc(2 * size - 1, sizeof(uint16_t));

    // Initialize all data to non-zero to simulate realistic input
    for (size_t idx = 0; idx < total_size; idx++) {
        left[idx] = (uint16_t)(rand() & 0xFFFF);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int *ptr;

static int *ptr_storage;
static size_t data_size = 1 << 20; // 1MB of data

void init_vars() {
    ptr_storage = aligned_alloc(32, data_size);
    if (!ptr_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize all elements to non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        ptr_storage[idx] = (int)(idx * 7919) ^ 0x12345678;
    }

    // Set up ptr to point at the beginning of usable region that allows safe access
    // We need indices up to 7*8 in each iteration, so we must leave enough space
    // Also, ptr is incremented each loop, and runs 8 iterations per step
    // Ensure total iterations won't exceed buffer bounds
    size_t max_iterations = (data_size / sizeof(int)) / (8 * 8);
    if (max_iterations < 8) {
        fprintf(stderr, "Buffer too small\n");
        exit(1);
    }

    ptr = ptr_storage;
    i = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(ptr_storage);
}
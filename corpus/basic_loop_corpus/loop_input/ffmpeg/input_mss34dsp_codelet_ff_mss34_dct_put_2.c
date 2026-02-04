#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int *ptr;

static int *ptr_base;
static size_t data_size;
static size_t num_iterations;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    size_t num_elements = data_size / sizeof(int);
    
    // Adjust to ensure multiple of 8 for full loop iterations
    num_elements = (num_elements / 8) * 8;
    if (num_elements == 0) num_elements = 8;
    
    ptr_base = (int*)aligned_alloc(32, num_elements * sizeof(int));
    if (!ptr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize array with non-zero values for meaningful computation
    for (size_t idx = 0; idx < num_elements; ++idx) {
        ptr_base[idx] = (int)(idx * 7919 % 1000); // Prime multiplier for pseudo-randomness
    }
    
    ptr = ptr_base;
    i = 0;
    num_iterations = num_elements / 8;
}

// Cleanup function to avoid memory leaks (if needed in test harness)
void free_vars() {
    if (ptr_base) {
        free(ptr_base);
        ptr_base = NULL;
    }
}
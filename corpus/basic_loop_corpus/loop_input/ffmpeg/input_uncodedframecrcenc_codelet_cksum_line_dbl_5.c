#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

unsigned int size;
double *p;
unsigned int a;
unsigned int b;

static double *p_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M doubles = 512MB, tuned for ~0.01s on modern CPU
    
    p_storage = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!p_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize with pseudo-random data for realistic computation
    srand(12345);
    for (size_t i = 0; i < data_size; i++) {
        p_storage[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // in range [-1.0, 1.0]
    }
    
    // Initialize external variables
    size = data_size;
    p = p_storage;
    a = 1;
    b = 0;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
void cleanup_vars() {
    if (p_storage) {
        free(p_storage);
        p_storage = NULL;
    }
}
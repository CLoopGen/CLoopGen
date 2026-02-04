#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;
typedef float real;

integer n_storage;
real *z__ = NULL;
integer k;

void init_vars() {
    // Estimate data size for ~0.01s runtime: use 64M floats (256 MB) as starting point
    size_t total_size = 1 << 26; // 64M elements
    z__ = (real *)aligned_alloc(32, total_size * sizeof(real));
    if (!z__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(z__, 0, total_size * sizeof(real));

    // Set n such that the loop runs enough iterations without OOB access
    // Loop accesses indices up to k*2 and k<<1-3 -> max index is about 2*k
    // We require 2*k <= total_size-1 -> k <= (total_size-1)/2
    // Initial k = *n << 1, so *n << 1 <= (total_size-1)/2 -> *n <= (total_size-1)/4
    n_storage = (total_size - 1) / 4;
    
    // Ensure at least a few iterations even if size calculation is off
    if (n_storage < 1000) {
        n_storage = 1000;
        // Reallocate if needed
        free(z__);
        total_size = (n_storage << 2) + 10;
        z__ = (real *)aligned_alloc(32, total_size * sizeof(real));
        if (!z__) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
        memset(z__, 0, total_size * sizeof(real));
    }

    // Initialize some values in z__ to avoid all-zero input
    for (size_t i = 0; i < total_size; i += 131) {
        z__[i] = (real)(i * 0.5f);
    }
}

// Define external symbols
integer *n = &n_storage;
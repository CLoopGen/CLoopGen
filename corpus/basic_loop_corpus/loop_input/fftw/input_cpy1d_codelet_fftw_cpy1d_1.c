#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
R *O;
INT n0;
INT is0;
INT os0;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    const size_t num_elements = total_size / sizeof(R);
    const size_t half_elements = num_elements / 2;

    // Ensure we have at least 2 elements per access
    if (half_elements < 2) {
        n0 = 1;
    } else {
        n0 = half_elements - 1; // Adjust so I[n0*is0 + 1] and O[n0*os0 + 1] are valid
    }

    is0 = 1;
    os0 = 1;

    // Allocate input and output arrays with padding to prevent out-of-bounds
    I = (R*)aligned_alloc(32, (n0 + 1) * is0 * sizeof(R) + 8);
    O = (R*)aligned_alloc(32, (n0 + 1) * os0 * sizeof(R) + 8);

    // Initialize input data
    for (INT i = 0; i < (n0 + 1) * is0; ++i) {
        I[i] = (R)(i * 1.5);
    }

    // Zero output array
    for (INT i = 0; i < (n0 + 1) * os0; ++i) {
        O[i] = 0.0;
    }
}
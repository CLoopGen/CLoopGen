#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *e;
integer i__1;
real c__;
integer i__;
integer m;
real p;
real r__;
real s;
real bb;
real oldc;
real gamma;
real alpha;
real sigma;
real oldgam;

static real *d_array;
static real *e_array;
static size_t array_size;

void init_vars() {
    // Estimate data size to achieve ~0.01s runtime
    // The loop has O(n) complexity with moderate operations per iteration.
    // On a modern CPU, 1M-10M iterations typically take ~0.01s.
    // We choose 8 million elements to ensure sufficient work without overkill.

    array_size = 8000000;

    // Allocate arrays with padding to prevent out-of-bounds access
    d_array = (real*)calloc(array_size + 4, sizeof(real)); // +2 before, +2 after for safety
    e_array = (real*)calloc(array_size + 2, sizeof(real)); // +1 before, +1 after

    if (!d_array || !e_array) {
        exit(1);
    }

    // Initialize pointers
    d__ = d_array + 1;  // Allow index from 1 to array_size+1 at least
    e = e_array + 1;

    // Set loop bounds
    m = 1;
    i__1 = array_size;

    // Initialize scalar variables
    c__ = 1.0f;
    p = 1.0f;
    sigma = 0.5f;
    gamma = 0.0f;
    oldgam = 0.0f;

    // Initialize array contents to avoid NaN/inf issues
    for (size_t idx = 0; idx < array_size + 2; ++idx) {
        if (idx < array_size)
            d__[idx] = (real)(idx + 1) * 0.1f;
        if (idx < array_size)
            e[idx] = (real)(idx + 1) * 0.2f;
    }

    // Ensure d__[i__+1] is valid when i__ == i__1
    d__[array_size + 1] = 1.0f;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

real *z__;
real *delta;
real *work;
integer i__1;
integer j;
real psi;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assume typical modern CPU does ~1e9 operations/sec; aim for ~1e7 iterations
    i__1 = 1 << 24;  // 16,777,216 elements (~64 MB per array, total ~192 MB)

    // Allocate arrays
    z__ = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    delta = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    work = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));

    // Initialize arrays to avoid division by zero and provide meaningful computation
    for (int i = 1; i <= i__1; ++i) {
        z__[i] = (real)(rand() % 100) / 100.0f;
        delta[i] = (real)(rand() % 100 + 1) / 100.0f;  // Ensure non-zero
        work[i] = (real)(rand() % 100 + 1) / 100.0f;   // Ensure non-zero
    }

    // Initialize scalar variables
    j = 0;
    psi = 0.0f;
}
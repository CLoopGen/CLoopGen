#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *x;
real *scale;
real *sumsq;
integer i__1;
integer i__2;
real r__1;
integer ix;
real absxi;

void init_vars() {
    // Allocate large arrays to ensure loop runs about 0.01 seconds
    // Assuming typical CPU can do ~1e8 operations/sec, aim for ~1e6 iterations
    const size_t array_size = 1 << 20;  // 1M elements

    x = (real*)aligned_alloc(32, array_size * sizeof(real));
    if (!x) abort();

    // Initialize control variables
    i__1 = array_size - 1;  // upper bound of loop index
    i__2 = 1;               // increment

    // Allocate and initialize scale and sumsq
    scale = (real*)aligned_alloc(32, sizeof(real));
    sumsq = (real*)aligned_alloc(32, sizeof(real));
    
    if (!scale || !sumsq) abort();

    *scale = 1.0f;
    *sumsq = 1.0f;

    // Initialize x array with non-zero values to trigger conditional logic
    for (size_t i = 0; i < array_size; ++i) {
        x[i] = (real)((double)rand() / RAND_MAX * 2.0 - 1.0);  // random in [-1, 1]
    }

    // Ensure first few values are non-zero to trigger condition early
    x[1] = 1.5f;
    x[2] = 0.8f;
}
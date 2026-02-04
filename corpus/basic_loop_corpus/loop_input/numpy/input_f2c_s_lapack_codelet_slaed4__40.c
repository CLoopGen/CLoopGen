#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

real *z__;
real *delta;
integer i__1;
integer j;
real psi;
real dpsi;
real temp;
real erretm;

void init_vars() {
    // Set array size to achieve ~0.01 sec runtime
    // Assuming typical modern CPU can do ~1e9 operations/sec
    // Loop has 4 operations per iteration, target ~1e7 iterations for 0.01 sec
    i__1 = 10000000;  // 10 million elements
    
    // Allocate arrays
    z__ = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    delta = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    
    // Initialize arrays to prevent NaN/inf that could cause issues
    for (int i = 1; i <= i__1; ++i) {
        z__[i] = 1.0f + (i % 100) * 0.01f;
        delta[i] = 0.5f + (i % 50) * 0.02f;
    }
    
    // Initialize scalar variables
    psi = 0.0f;
    dpsi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
    j = 0;  // Will be set in loop
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
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
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays (z__ and delta)
    i__1 = (integer)(data_size / sizeof(real));
    
    z__ = (real*)aligned_alloc(32, data_size);
    delta = (real*)aligned_alloc(32, data_size);

    if (!z__ || !delta) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (integer idx = 0; idx <= i__1; ++idx) {
        z__[idx] = (real)(drand48() * 2.0 - 1.0);
        delta[idx] = (real)(drand48() * 1.0 + 0.5); // Avoid division by zero
    }

    psi = 0.0f;
    dpsi = 0.0f;
    erretm = 0.0f;
    j = 0;
}
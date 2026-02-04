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
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (two arrays)
    i__1 = data_size - 1; // ensures j from 1 to i__1 is valid index for 0-indexed arrays

    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    delta = (real*)aligned_alloc(32, data_size * sizeof(real));

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (real)(drand48() * 2.0 - 1.0); // random between -1 and 1
        delta[i] = (real)(drand48() + 1e-7);   // prevent division by zero
    }

    psi = 0.0;
    dpsi = 0.0;
    erretm = 0.0;
    j = 0;
    temp = 0.0;
}
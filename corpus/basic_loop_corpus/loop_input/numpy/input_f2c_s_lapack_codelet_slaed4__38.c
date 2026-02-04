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

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total (two arrays)
    i__1 = data_size;

    z__ = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    delta = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));

    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = (real)(i % 1000) / 100.0f;
        delta[i] = (real)(i % 800) / 50.0f + 1e-3f;
    }

    psi = 0.0f;
}
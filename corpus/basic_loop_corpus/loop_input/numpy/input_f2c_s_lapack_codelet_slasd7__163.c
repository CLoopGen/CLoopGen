#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *z__;
real *vf;
real *beta;
integer i__1;
integer i__;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for float arrays (64M elements)

    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    vf = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!z__ || !vf) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = 1.0f;
        vf[i] = 2.0f + i % 100;
    }

    beta = (real*)aligned_alloc(32, sizeof(real));
    if (!beta) {
        exit(1);
    }
    *beta = 0.5f;

    nlp2 = 0;
    i__1 = data_size - 1;
}
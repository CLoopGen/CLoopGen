#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *x;
integer i__1;
integer i__2;
real r__1;
integer ix;
real ssq;
real scale;
real absxi;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of float data
    x = (real*)aligned_alloc(32, sizeof(real) * (data_size + 1));
    if (!x) exit(1);

    for (size_t i = 1; i <= data_size; ++i) {
        x[i] = (real)(drand48() * 2.0 - 1.0); // random values in [-1, 1]
    }

    i__1 = data_size;
    i__2 = 1;

    scale = 1.0f;
    ssq = 1.0f;
}
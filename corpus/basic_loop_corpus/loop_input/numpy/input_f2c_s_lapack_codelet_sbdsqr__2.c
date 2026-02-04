#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *e;
integer i__1;
real r__1;
real r__2;
real r__3;
integer i__;
real smax;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    e = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!e) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (real)(drand48() * 2.0 - 1.0) * 1e3f;
    }

    i__1 = (integer)(data_size - 1);
    smax = 0.0f;
    r__1 = r__2 = r__3 = 0.0f;
    i__ = 0;
}
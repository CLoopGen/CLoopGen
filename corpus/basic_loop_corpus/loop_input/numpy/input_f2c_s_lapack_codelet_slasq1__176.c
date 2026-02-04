#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__ = NULL;
integer i__1;
real r__1;
real r__2;
integer i__;
real sigmx;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million elements, approx 256MB for float
    d__ = (real*)calloc(data_size, sizeof(real));
    if (!d__) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        d__[idx] = (real)(rand() % 1000) / 10.0f;
    }

    i__1 = (integer)(data_size - 1);
    sigmx = 10.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    i__ = 1;
}
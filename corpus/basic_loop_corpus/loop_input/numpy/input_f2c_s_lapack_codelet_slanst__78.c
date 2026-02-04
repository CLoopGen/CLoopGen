#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__;
real *e;
integer i__1;
real r__1;
real r__2;
real r__3;
integer i__;
real anorm;

void init_vars() {
    // Set problem size to achieve approximately 0.01 seconds runtime
    // Based on typical performance, ~64M elements should be sufficient
    i__1 = 65536000;  // 65.5 million elements

    // Allocate arrays d__ and e with appropriate size
    d__ = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    e = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));

    if (d__ == NULL || e == NULL) {
        exit(1);
    }

    // Initialize arrays with sample data to avoid NaN or undefined behavior
    for (integer i = 1; i <= i__1; ++i) {
        d__[i] = sinf((float)i * 0.0001f);
        e[i] = cosf((float)i * 0.0001f);
    }

    // Initialize anorm to zero so it can accumulate maximum norm
    anorm = 0.0f;
}
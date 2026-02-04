#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer a_dim1;
integer i__1;
integer i__;
integer j;
real temp;
logical nounit;

void init_vars() {
    // Allocate and initialize n
    static integer n_val = 2048;  // Choose size so that A is ~16MB: 2048*2048*sizeof(float) ≈ 16.8MB
    n = &n_val;

    // Set matrix dimension
    a_dim1 = *n;

    // Allocate arrays
    a = (real*)calloc(*n * *n, sizeof(real));
    x = (real*)calloc(*n, sizeof(real));

    // Initialize arrays with non-zero values to ensure meaningful computation
    for (integer idx = 0; idx < *n; ++idx) {
        x[idx] = sinf(idx);
        for (integer jdx = 0; jdx <= idx; ++jdx) {  // Only use lower triangle
            a[idx + jdx * a_dim1] = cosf(idx * 31 + jdx * 57) * 0.01f;
        }
    }

    // Ensure diagonal is not unity
    nounit = 1;

    // Initialize scalars used in loop
    i__1 = 0;
    i__ = 0;
    j = 0;
    temp = 0.0f;
}
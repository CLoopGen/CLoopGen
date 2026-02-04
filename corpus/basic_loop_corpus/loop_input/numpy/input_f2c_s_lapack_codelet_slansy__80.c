#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *a;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
real r__2;
real r__3;
integer i__;
integer j;
real value;

void init_vars() {
    a_dim1 = 4096;
    i__1 = 4096;
    a = (real*)aligned_alloc(32, (size_t)a_dim1 * (size_t)i__1 * sizeof(real));
    if (!a) {
        exit(1);
    }
    for (integer idx = 0; idx < a_dim1 * i__1; ++idx) {
        a[idx] = (real)(drand48() * 2.0 - 1.0);
    }
    value = 0.0f;
}
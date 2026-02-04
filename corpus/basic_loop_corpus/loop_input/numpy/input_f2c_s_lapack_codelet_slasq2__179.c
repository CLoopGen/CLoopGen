#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *z__;
integer i__1;
real r__1;
real r__2;
real d__;
integer k;
integer i0;
integer i4;
integer n0;
integer pp;
real tol2;
real emin;
real temp;
real qmax;
real safmin;

void init_vars() {
    n0 = 1024;
    i0 = 1;
    pp = 0;
    tol2 = 1e-6f;
    safmin = sqrtf(1e-37f);

    size_t z_size = (n0 << 2) + 4;
    z__ = (real*)calloc(z_size, sizeof(real));
    if (!z__) exit(1);

    for (size_t i = 0; i < z_size; ++i) {
        z__[i] = 1.0f + 0.01f * (i & 31);
    }
}
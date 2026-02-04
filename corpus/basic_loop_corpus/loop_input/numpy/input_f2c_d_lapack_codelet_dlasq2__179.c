#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__;
integer k;
integer i0;
integer i4;
integer n0;
integer pp;
doublereal tol2;
doublereal emin;
doublereal temp;
doublereal qmax;
doublereal safmin;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data (adjustable)
    z__ = (doublereal*)aligned_alloc(32, total_size * sizeof(doublereal));
    
    if (!z__) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        z__[i] = fabs(sin((double)i)) + 1.0; 
    }

    i0 = 10;
    n0 = 50;
    pp = 0;

    tol2 = 1e-12;
    safmin = 1e-18;

    d__ = 0.0;
    emin = 1e30;
    temp = 0.0;
    qmax = 0.0;
}

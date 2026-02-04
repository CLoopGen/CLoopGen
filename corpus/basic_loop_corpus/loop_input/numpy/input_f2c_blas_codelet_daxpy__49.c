#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *da;
doublereal *dx;
integer *incx;
doublereal *dy;
integer *incy;
integer i__1;
integer i__;
integer ix;
integer iy;

void init_vars() {
    // Allocate arrays with ~64MB of data each (about 8 million doubles)
    const size_t N = 8000000;
    
    dx = (doublereal*)calloc(N, sizeof(doublereal));
    dy = (doublereal*)calloc(N, sizeof(doublereal));
    da = (doublereal*)malloc(sizeof(doublereal));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    // Initialize scalar values
    *da = 2.0;
    *incx = 1;
    *incy = 1;

    // Set loop bounds to stay within array limits
    i__1 = N - 1;  // ensures ix and iy never exceed array bounds
    i__ = 1;
    ix = 0;
    iy = 0;

    // Initialize input arrays with non-zero values for meaningful computation
    for (size_t j = 0; j < N; ++j) {
        dx[j] = (doublereal)(j + 1);
        dy[j] = (doublereal)(j + 1) * 0.5;
    }
}
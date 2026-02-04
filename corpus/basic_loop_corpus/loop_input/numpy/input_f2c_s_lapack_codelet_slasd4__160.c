#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *delta;
real *work;
integer i__1;
integer j;
integer ip1;
real eta;

void init_vars() {
    i__1 = 10000000;  // 10 million elements for ~0.01 sec runtime
    ip1 = 1;          // assuming ip1 is used as j+1 offset, so d__[j] and d__[ip1] valid for j from 1 to i__1

    // Allocate arrays with extra space to avoid out-of-bounds access (index up to i__1, using j and ip1=j+1)
    d__ = (real*)calloc(i__1 + 2, sizeof(real));
    delta = (real*)calloc(i__1 + 1, sizeof(real));
    work = (real*)calloc(i__1 + 1, sizeof(real));

    eta = 1.0f;

    // Initialize d__ array to non-zero values for meaningful computation
    for (int i = 1; i <= i__1 + 1; ++i) {
        d__[i] = (real)(i % 100);
    }
}
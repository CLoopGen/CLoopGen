#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *beta;
real *y;
integer *incy;
integer i__1;
integer i__;
integer iy;

void init_vars() {
    // Allocate and initialize beta
    beta = (real*)aligned_alloc(32, sizeof(real));
    *beta = 2.0f;

    // Determine problem size: aim for ~100ms execution
    // The loop does one multiply-add per iteration; modern CPUs do several GFLOPs,
    // so we need on the order of 10M-50M elements to reach 0.01 seconds.
    i__1 = 20000000;  // 20 million iterations

    // Allocate y array
    y = (real*)aligned_alloc(32, i__1 * sizeof(real));
    for (int i = 0; i < i__1; ++i) {
        y[i] = (real)(i + 1);
    }

    // Allocate and initialize incy
    incy = (integer*)aligned_alloc(32, sizeof(integer));
    *incy = 1;  // typical stride

    // Initialize index variables
    i__ = 1;
    iy = 0;  // base index for y, assuming 0-based C array vs 1-based logic in loop
}
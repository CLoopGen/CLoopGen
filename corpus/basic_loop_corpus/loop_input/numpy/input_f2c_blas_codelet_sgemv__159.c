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
    beta = (real*)malloc(sizeof(real));
    *beta = 2.5f;

    // Set vector length to achieve ~0.01 sec runtime
    // Assuming typical modern CPU can do ~1e8 operations/sec, use ~1e6 elements for 0.01 sec
    i__1 = 1000000;
    i__ = 1;

    // Allocate y array
    y = (real*)malloc(i__1 * sizeof(real));
    if (!y) {
        exit(1);
    }
    for (int i = 0; i < i__1; ++i) {
        y[i] = (real)(i + 1) * 0.5f;
    }

    // incy: increment for y indexing
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    // Initialize starting index iy (1-based indexing as per loop)
    iy = 0; // Will be used as 0-based offset in C
}
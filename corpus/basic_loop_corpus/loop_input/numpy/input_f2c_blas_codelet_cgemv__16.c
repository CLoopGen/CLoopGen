#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *beta;
singlecomplex *y;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
integer i__;
integer iy;

void init_vars() {
    // Allocate and initialize beta
    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta->r = 1.5f;
    beta->i = 0.8f;

    // Set vector length to achieve ~0.01 sec runtime
    // Assuming moderate CPU speed and memory bandwidth
    // Use about 4-8 million elements for float complex (8 bytes per element)
    i__1 = 6000000;  // Loop runs 6e6 iterations

    // Allocate y array
    y = (singlecomplex*)calloc(i__1, sizeof(singlecomplex));
    for (int j = 0; j < i__1; ++j) {
        y[j].r = (real)(j % 100) / 100.0f;
        y[j].i = (real)((j + 10) % 100) / 100.0f;
    }

    // Allocate and initialize incy
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;  // typical increment

    // Initialize loop index and pointer
    i__ = 1;
    iy = 0;  // start at beginning of y array

    // Ensure no out-of-bounds: iy will go from 0 to i__1-1
    // with *incy = 1 and i__1 elements allocated
}
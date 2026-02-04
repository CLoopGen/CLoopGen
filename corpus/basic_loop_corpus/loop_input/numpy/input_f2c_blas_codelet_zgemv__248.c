#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *beta;
doublecomplex *y;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
integer i__;
integer iy;

void init_vars() {
    // Allocate and initialize beta
    beta = (doublecomplex*)malloc(sizeof(doublecomplex));
    beta->r = 1.5;
    beta->i = 0.8;

    // Determine problem size to achieve ~0.01 sec runtime
    // Each iteration processes one complex number (16 bytes)
    // Assume modern CPU can do ~1e9 operations/sec -> target ~1e7 operations
    // Use 4 million elements (~64 MB) as a reasonable estimate for 0.01 sec
    const int N = 4000000;
    
    // Allocate y array
    y = (doublecomplex*)calloc(N, sizeof(doublecomplex));
    
    // Initialize some sample values in y
    for (int j = 0; j < N && j < 10; ++j) {
        y[j].r = 1.0 + j * 0.1;
        y[j].i = 0.5 + j * 0.05;
    }

    // Set increment: use increment of 1 for dense access
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    // Set loop bounds to stay within allocated memory
    i__1 = N;  // number of iterations
    i__ = 1;   // loop index starts at 1
    iy = 0;    // starting index in y array (0-based)

    // Initialize temporaries
    i__2 = 0;
    i__3 = 0;
    z__1.r = 0.0;
    z__1.i = 0.0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <float.h>

typedef int integer;
typedef double doublereal;

integer *i0;
doublereal *z__;
doublereal *dmin__;
integer i__1;
doublereal d__1;
doublereal d__2;
doublereal d__;
integer j4;
doublereal emin;
doublereal temp;
doublereal safmin;

void init_vars() {
    // Allocate and initialize i0
    i0 = (integer*)malloc(sizeof(integer));
    *i0 = 1;

    // Set loop bounds to ensure safe access within z__
    // The loop uses indices: j4-2, j4-1, j4, j4+1 -> need at least up to index i__1+1
    // Choose problem size so that loop runs ~0.01 seconds -> aim for ~1M iterations
    i__1 = 1 << 20;  // 1 million iterations

    // Allocate z__ array with extra padding to prevent out-of-bounds access
    z__ = (doublereal*)calloc(i__1 + 2, sizeof(doublereal));

    // Initialize z__ with non-zero values where needed to avoid division by zero
    for (int i = 0; i < i__1 + 2; ++i) {
        z__[i] = 1.0 + 0.01 * (i % 7);  // Small variation to prevent accidental zeros
    }

    // Allocate and initialize dmin__
    dmin__ = (doublereal*)malloc(sizeof(doublereal));
    *dmin__ = 1.0;

    // Initialize scalar variables
    d__ = 1.0;
    emin = 1.0;
    temp = 1.0;
    safmin = DBL_MIN;  // Now correctly using DBL_MIN from <float.h>
}
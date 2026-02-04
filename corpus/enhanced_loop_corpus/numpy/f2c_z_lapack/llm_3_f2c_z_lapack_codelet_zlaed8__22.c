#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern doublereal *dlamda;
extern doublereal *w;
extern integer *indx;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing — process every second element forward and backward
    // This creates a strided, non-unit-stride access pattern over the indx array, accessing elements with stride 2
    integer upper_bound = i__1;
    integer stride = 2;

    // Forward pass: process odd indices (1, 3, 5, ...)
    for (i__ = 1; i__ <= upper_bound; i__ += stride) {
        d__[i__] = dlamda[indx[i__]];
        z__[i__] = w[indx[i__]];
    }

    // Backward pass: process even indices in reverse (..., 6, 4, 2)
    for (i__ = (upper_bound % 2 == 0) ? upper_bound : upper_bound - 1; i__ >= 2; i__ -= stride) {
        d__[i__] = dlamda[indx[i__]];
        z__[i__] = w[indx[i__]];
    }
}

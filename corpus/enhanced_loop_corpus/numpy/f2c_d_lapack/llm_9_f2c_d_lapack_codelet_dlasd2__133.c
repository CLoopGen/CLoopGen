#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern doublereal *dsigma;
extern doublereal *u2;
extern integer *idxc;
extern integer *idxq;
extern integer *coltyp;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and unrolled by factor of 2 with simplified operations
    integer inc = 2;
    for (i__ = 2; i__ <= i__1 - 1; i__ += inc) {
        // Unroll factor 2: process two iterations per loop
        dsigma[i__] = d__[idxq[i__]];
        u2[i__ + u2_dim1] = z__[idxq[i__]];
        idxc[i__] = coltyp[idxq[i__]];

        dsigma[i__+1] = d__[idxq[i__+1]];
        u2[i__+1 + u2_dim1] = z__[idxq[i__+1]];
        idxc[i__+1] = coltyp[idxq[i__+1]];
    }
    // Handle odd-sized remainder if needed
    if (i__ <= i__1) {
        dsigma[i__] = d__[idxq[i__]];
        u2[i__ + u2_dim1] = z__[idxq[i__]];
        idxc[i__] = coltyp[idxq[i__]];
    }
}

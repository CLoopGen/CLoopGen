#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern doublereal *zw;
extern doublereal *vf;
extern doublereal *vfw;
extern doublereal *vl;
extern doublereal *vlw;
extern doublereal *dsigma;
extern integer *idxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Remove potential aliasing and break loop-carried dependencies by reordering independent operations
    // and separating reads from writes to eliminate false dependencies
    // Also, unroll the loop partially to change data access pattern (semantic equivalence preserved)

    i__ = 2;
    while (i__ <= i__1 - 3) {
        // Process 4 elements per iteration to reduce loop overhead and change dependency exposure
        dsigma[i__]   = d__[idxq[i__]];
        zw[i__]      = z__[idxq[i__]];
        vfw[i__]     = vf[idxq[i__]];
        vlw[i__]     = vl[idxq[i__]];

        dsigma[i__+1] = d__[idxq[i__+1]];
        zw[i__+1]    = z__[idxq[i__+1]];
        vfw[i__+1]   = vf[idxq[i__+1]];
        vlw[i__+1]   = vl[idxq[i__+1]];

        dsigma[i__+2] = d__[idxq[i__+2]];
        zw[i__+2]    = z__[idxq[i__+2]];
        vfw[i__+2]   = vf[idxq[i__+2]];
        vlw[i__+2]   = vl[idxq[i__+2]];

        dsigma[i__+3] = d__[idxq[i__+3]];
        zw[i__+3]    = z__[idxq[i__+3]];
        vfw[i__+3]   = vf[idxq[i__+3]];
        vlw[i__+3]   = vl[idxq[i__+3]];

        i__ += 4;
    }
    // Clean up remaining elements
    for (; i__ <= i__1; ++i__) {
        dsigma[i__] = d__[idxq[i__]];
        zw[i__] = z__[idxq[i__]];
        vfw[i__] = vf[idxq[i__]];
        vlw[i__] = vl[idxq[i__]];
    }
}

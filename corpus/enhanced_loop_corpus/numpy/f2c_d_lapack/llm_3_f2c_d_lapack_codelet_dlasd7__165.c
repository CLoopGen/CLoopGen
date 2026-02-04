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
    // Variant 2: Strided memory access with indirect indexing
    // Access elements using a stride of 2 over the idxq indices to create non-consecutive access
    integer stride = 2;
    integer count = (i__1 - 2 + 1 + stride - 1) / stride; // Number of iterations under striding
    for (i__ = 0; i__ < count; ++i__) {
        integer j = 2 + i__ * stride; // Map to original index space
        if (j > i__1) break;
        dsigma[j] = d__[idxq[j]];
        zw[j] = z__[idxq[j]];
        vfw[j] = vf[idxq[j]];
        vlw[j] = vl[idxq[j]];
    }
}

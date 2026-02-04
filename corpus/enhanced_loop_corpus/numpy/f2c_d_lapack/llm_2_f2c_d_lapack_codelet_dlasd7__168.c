#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *vf;
extern doublereal *vfw;
extern doublereal *vl;
extern doublereal *vlw;
extern doublereal *dsigma;
extern integer *idxp;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (forward) memory access with stride of 1
    // Instead of indirect indexing via idxp, we assume data is already ordered and access consecutively
    for (j = 2; j <= i__1; ++j) {
        dsigma[j] = d__[j];      // Direct consecutive access
        vfw[j] = vf[j];          // Contiguous read
        vlw[j] = vl[j];          // Contiguous read
    }
}

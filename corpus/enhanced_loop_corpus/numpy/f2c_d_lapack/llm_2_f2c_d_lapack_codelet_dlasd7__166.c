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
extern integer *idx;
extern integer i__1;
extern integer i__;
extern integer idxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (forward) memory access with array base shift
    // Instead of indirect indexing via idx[i__], we assume a consecutive layout after sorting or preprocessing.
    // This variant assumes that dsigma, zw, vfw, vlw are now stored consecutively starting from index 1.
    for (i__ = 2; i__ <= i__1; ++i__) {
        d__[i__] = dsigma[i__];
        z__[i__] = zw[i__];
        vf[i__] = vfw[i__];
        vl[i__] = vlw[i__];
    }
}

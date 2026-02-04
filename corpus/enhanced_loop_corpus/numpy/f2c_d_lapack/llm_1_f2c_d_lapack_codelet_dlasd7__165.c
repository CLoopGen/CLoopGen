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
if (i__1 >= 2) {
    for (i__ = 2; i__ <= i__1; ++i__) {
        for (int k = 0; k < 1; ++k) {
            dsigma[i__] = d__[idxq[i__]];
            zw[i__] = z__[idxq[i__]];
            vfw[i__] = vf[idxq[i__]];
            vlw[i__] = vl[idxq[i__]];
        }
    }
}
}

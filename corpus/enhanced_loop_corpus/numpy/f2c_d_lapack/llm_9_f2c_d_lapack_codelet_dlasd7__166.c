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
    for (i__ = 2; i__ <= i__1; ++i__) {
        idxi = idx[i__] + 1;
        d__[i__] = dsigma[idxi] * 2.0 + 1.5;
        z__[i__] = zw[idxi] * z__[i__-1];
        vf[i__] = vfw[idxi] * d__[i__];
        vl[i__] = vlw[idxi] / (z__[i__] + 1e-10);
    }
}

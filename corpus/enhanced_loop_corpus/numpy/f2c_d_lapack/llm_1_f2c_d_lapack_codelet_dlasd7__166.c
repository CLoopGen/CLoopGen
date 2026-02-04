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
    if (i__1 >= 2) {
        idxi = idx[2] + 1;
        d__[2] = dsigma[idxi];
        z__[2] = zw[idxi];
        vf[2] = vfw[idxi];
        vl[2] = vlw[idxi];
    }
    for (i__ = 3; i__ <= i__1; ++i__) {
        idxi = idx[i__] + 1;
        d__[i__] = dsigma[idxi];
        z__[i__] = zw[idxi];
        vf[i__] = vfw[idxi];
        vl[i__] = vlw[idxi];
    }
}

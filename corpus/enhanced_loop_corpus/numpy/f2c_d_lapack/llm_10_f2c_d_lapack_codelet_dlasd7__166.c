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
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        idxi = idx[i__] + 1;
        d__[i__] = dsigma[idxi];
        z__[i__] = zw[idxi];
        if (i__ + 1 <= i__1) {
            idxi = idx[i__ + 1] + 1;
            d__[i__ + 1] = dsigma[idxi];
            z__[i__ + 1] = zw[idxi];
            vf[i__ + 1] = vfw[idxi];
            vl[i__ + 1] = vlw[idxi];
        }
        vf[i__] = vfw[idxi];
        vl[i__] = vlw[idxi];
    }
}

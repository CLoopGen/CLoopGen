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
    if (i__1 >= 2) {
        j = 2;
        dsigma[j] = d__[idxp[j]];
        vfw[j] = vf[idxp[j]];
        vlw[j] = vl[idxp[j]];
        for (j = 3; j <= i__1; ++j) {
            jp = idxp[j];
            dsigma[j] = d__[jp];
            vfw[j] = vf[jp];
            vlw[j] = vl[jp];
        }
    }
}

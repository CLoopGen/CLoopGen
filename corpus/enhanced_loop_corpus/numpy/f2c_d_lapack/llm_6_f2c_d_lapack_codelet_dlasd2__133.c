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
    doublereal prev_dsigma = d__[idxq[1]];
    for (i__ = 2; i__ <= i__1; ++i__) {
        dsigma[i__] = prev_dsigma + d__[idxq[i__]] - d__[idxq[i__-1]];
        u2[i__ + u2_dim1] = z__[idxq[i__]];
        idxc[i__] = coltyp[idxq[i__]];
        prev_dsigma = dsigma[i__];
    }
}

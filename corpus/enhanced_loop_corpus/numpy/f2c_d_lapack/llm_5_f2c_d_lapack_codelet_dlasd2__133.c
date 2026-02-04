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
    for (i__ = 2; i__ <= i__1; ++i__) {
        if (idxq[i__] > 0) {
            dsigma[i__] = d__[idxq[i__]];
            u2[i__ + u2_dim1] = z__[idxq[i__]];
            idxc[i__] = coltyp[idxq[i__]];
        } else {
            dsigma[i__] = 0.0;
            u2[i__ + u2_dim1] = 0.0;
            idxc[i__] = 0;
        }
    }
}

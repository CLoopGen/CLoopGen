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
    integer temp_idx;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp_idx = idxq[i__];
        dsigma[i__] = d__[temp_idx];
        u2[i__ + u2_dim1] = z__[temp_idx];
        idxc[i__] = coltyp[temp_idx];
    }
}

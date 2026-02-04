#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern real *dsigma;
extern real *u2;
extern integer *idxc;
extern integer *idxq;
extern integer *coltyp;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_dsigma;
    real temp_u2;
    integer temp_idxc;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp_dsigma = d__[idxq[i__]];
        temp_u2 = z__[idxq[i__]];
        temp_idxc = coltyp[idxq[i__]];
        dsigma[i__] = temp_dsigma;
        u2[i__ + u2_dim1] = temp_u2;
        idxc[i__] = temp_idxc;
    }
}

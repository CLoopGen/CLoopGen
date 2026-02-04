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
extern integer *idx;
extern integer *idxc;
extern integer *coltyp;
extern integer u2_dim1;
extern integer i__1;
extern integer i__;
extern integer idxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; i__ += 2) {
    integer idxi1 = idx[i__] + 1;
    d__[i__] = dsigma[idxi1];
    z__[i__] = u2[idxi1 + u2_dim1];
    coltyp[i__] = idxc[idxi1];

    if (i__ + 1 <= i__1) {
        integer idxi2 = idx[i__ + 1] + 1;
        d__[i__ + 1] = dsigma[idxi2];
        z__[i__ + 1] = u2[idxi2 + u2_dim1];
        coltyp[i__ + 1] = idxc[idxi2];
    }
}
}

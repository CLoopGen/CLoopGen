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
// Reduce trip count to increase per-iteration work density and modify access pattern
integer step = 2;
for (i__ = 2; i__ <= (i__1 + 1) / 2; ++i__) {
    integer j1 = 2 * i__ - 2;
    integer j2 = 2 * i__ - 1;
    if (j1 <= i__1) {
        idxi = idx[j1] + 1;
        d__[j1] = dsigma[idxi];
        z__[j1] = u2[idxi + u2_dim1];
        coltyp[j1] = idxc[idxi];
    }
    if (j2 <= i__1) {
        idxi = idx[j2] + 1;
        d__[j2] = dsigma[idxi];
        z__[j2] = u2[idxi + u2_dim1];
        coltyp[j2] = idxc[idxi];
    }
}
}

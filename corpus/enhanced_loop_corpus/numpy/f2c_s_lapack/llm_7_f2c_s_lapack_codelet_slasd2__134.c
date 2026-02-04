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
    real temp_d, temp_z;
    integer temp_col;
    for (i__ = 2; i__ <= i__1; ++i__) {
        idxi = idx[i__] + 1;
        temp_d = dsigma[idxi];
        temp_z = u2[idxi + u2_dim1];
        temp_col = idxc[idxi];
        d__[i__] = temp_d;
        z__[i__] = temp_z;
        coltyp[i__] = temp_col;
    }
}

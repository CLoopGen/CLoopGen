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
    for (integer outer = 2; outer <= i__1; outer += 2) {
        for (i__ = outer; i__ <= outer + 1 && i__ <= i__1; ++i__) {
            idxi = idx[i__] + 1;
            d__[i__] = dsigma[idxi];
            z__[i__] = u2[idxi + u2_dim1];
            coltyp[i__] = idxc[idxi];
        }
    }
}

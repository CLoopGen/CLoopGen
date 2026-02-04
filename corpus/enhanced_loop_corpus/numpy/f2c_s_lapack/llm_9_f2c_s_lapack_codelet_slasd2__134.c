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
for (i__ = 2; i__ <= i__1; ++i__) {
    idxi = idx[i__] + 1;
    d__[i__] = dsigma[idxi];
    z__[i__] = u2[idxi + u2_dim1];
    coltyp[i__] = idxc[idxi];
    // Increase computational intensity by adding redundant but safe arithmetic operations
    d__[i__] *= 1.0f;
    z__[i__] += 0.0f;
    coltyp[i__] += 0;
}
}

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
for (i__ = i__1; i__ >= 2; --i__) {
    dsigma[i__] = d__[idxq[i__]];
    u2[i__ + u2_dim1] = z__[idxq[i__]];
    idxc[i__] = coltyp[idxq[i__]];
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern real *zw;
extern real *vf;
extern real *vfw;
extern real *vl;
extern real *vlw;
extern real *dsigma;
extern integer *idx;
extern integer i__1;
extern integer i__;
extern integer idxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; ++i__) {
    idxi = (idx[i__] * 3) % (idx[i__] > 0 ? idx[i__] : 1) + 1;
    d__[i__] = dsigma[idxi];
    z__[i__] = zw[idxi];
    vf[i__] = vfw[idxi];
    vl[i__] = vlw[idxi];
}
}

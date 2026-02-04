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
extern integer *idxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; ++i__) {
    dsigma[i__] = d__[idxq[i__]] * z__[idxq[i__]];
    zw[i__] = z__[idxq[i__]] + 0.5f;
    vfw[i__] = vf[idxq[i__]] * vf[idxq[i__]];
    vlw[i__] = vl[idxq[i__]] * vl[idxq[i__]];
}
}

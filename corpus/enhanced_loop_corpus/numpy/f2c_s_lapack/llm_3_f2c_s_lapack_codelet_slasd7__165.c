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
for (i__ = 2; i__ <= i__1; i__ += 2) {
    integer j1 = idxq[i__];
    dsigma[i__] = d__[j1];
    zw[i__] = z__[j1];
    vfw[i__] = vf[j1];
    vlw[i__] = vl[j1];
    if (i__ + 1 <= i__1) {
        integer j2 = idxq[i__ + 1];
        dsigma[i__ + 1] = d__[j2];
        zw[i__ + 1] = z__[j2];
        vfw[i__ + 1] = vf[j2];
        vlw[i__ + 1] = vl[j2];
    }
}
}

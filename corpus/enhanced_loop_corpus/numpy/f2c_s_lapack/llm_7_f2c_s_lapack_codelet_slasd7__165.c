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
    real temp_d, temp_z, temp_vf, temp_vl;
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp_d = d__[idxq[i__]];
        temp_z = z__[idxq[i__]];
        temp_vf = vf[idxq[i__]];
        temp_vl = vl[idxq[i__]];

        dsigma[i__] = temp_d;
        zw[i__] = temp_z;
        vfw[i__] = temp_vf;
        vlw[i__] = temp_vl;
    }
}

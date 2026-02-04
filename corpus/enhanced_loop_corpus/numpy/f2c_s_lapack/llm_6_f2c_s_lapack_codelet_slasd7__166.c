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
    real temp_d, temp_z, temp_vf, temp_vl;
    for (i__ = 2; i__ <= i__1; ++i__) {
        idxi = idx[i__] + 1;
        temp_d = dsigma[idxi];
        temp_z = zw[idxi];
        temp_vf = vfw[idxi];
        temp_vl = vlw[idxi];
        d__[i__] = temp_d;
        z__[i__] = temp_z;
        vf[i__] = temp_vf;
        vl[i__] = temp_vl;
    }
}

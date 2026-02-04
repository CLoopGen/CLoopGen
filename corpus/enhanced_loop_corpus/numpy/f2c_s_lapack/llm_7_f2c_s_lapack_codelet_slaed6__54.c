#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern integer i__;
extern real dscale[3];
extern real sclfac;
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real accum_d = 0.0, accum_z = 0.0;
    for (i__ = 1; i__ <= 3; ++i__) {
        accum_d += d__[i__] * sclfac;
        accum_z += z__[i__] * sclfac;
        dscale[i__ - 1] = accum_d;
        zscale[i__ - 1] = accum_z;
    }
}
